#include <iostream>
#include "SmartRandom.h"

/*
 * The strategy here is to bomb randomly, but to follow
 * up promptly when a ship is found.
 */
unsigned SmartRandom::guess() {
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
    if (tracking[location]) {
        for (location = randSq(gen); 
                tracking[location]; 
                location = randSq(gen))
        { }
    }
    return location;
}

void SmartRandom::result(unsigned location, char bombresult)
{
    if (bombresult != Ocean::empty) {
        if (bombresult == Ocean::hit) {  // generic hit
            unsigned shortship = Ocean::shipcount-1;
            if (tracking.place(location, shortship, true, true))
                next.push_back(location+1);
            if (tracking.place(location, shortship, false, true))
                next.push_back(location+Ocean::dim);
            if (tracking.place(location-1, shortship, true, true))
                next.push_back(location-1);
            if (tracking.place(location-Ocean::dim, shortship, false, true))
                next.push_back(location-Ocean::dim);
        } else {  // specific ship was just sunk
            next.clear();
        }
    }
    tracking.record(location, bombresult); 
}

