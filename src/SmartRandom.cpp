#include <iostream>
#include "SmartRandom.h"

/*
 * The strategy here is to bomb randomly, but to follow
 * up promptly when a ship is found.
 */
bool SmartRandom::turn() {
    ++turns;
    unsigned location = randSq(gen);
    // try using our pre-stored guesses first
    if (!next.empty()) {
        for (location = next.back(); 
                tracking[location] && !next.empty(); 
                location = next.back())
        { 
            next.pop_back();
        }
    }
    if (tracking[location])
        for (location = randSq(gen); 
                tracking[location]; 
                location = randSq(gen))
        { }
    char result = ocean.bomb(location);
    if (result != ocean.empty) {
        if (result == ocean.hit) {  // generic hit
            unsigned shortship = ocean.shipcount-1;
            if (tracking.place(location, shortship, true, true))
                next.push_back(location+1);
            if (tracking.place(location, shortship, false, true))
                next.push_back(location+ocean.dim);
            if (tracking.place(location-1, shortship, true, true))
                next.push_back(location-1);
            if (tracking.place(location-ocean.dim, shortship, false, true))
                next.push_back(location-ocean.dim);
        } else {  // specific ship was just sunk
            next.clear();
        }
    }
    tracking.record(location, result); 
    if (verbose)
        std::cout << "\nTurn " << turns << ", bombing " << location 
            << "\nTracking:\n" << tracking 
            << '\n' << ocean 
            << std::endl;
    return ocean.remaining();
}
