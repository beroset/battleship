#include <iostream>
#include "SmarterRandom.h"

/*
 * The strategy here is to bomb mostly randomly, but 
 * to only randomly select every other point
 * and to follow up promptly when a ship is found.
 */
unsigned SmarterRandom::guess() {
    unsigned location = randLocation();
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
        for (location = randLocation(); 
                tracking[location]; 
                location = randLocation())
        { }
    }
    return location;
}

void SmarterRandom::result(unsigned location, char bombresult)
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
            //next.clear();
        }
    }
    tracking.record(location, bombresult); 
}

unsigned SmarterRandom::randLocation()
{
    unsigned loc = randSq(gen);
    // only allow the location if it's an odd row or odd colum
    // but not both
    for ( ; isBadLocation(loc); loc=randSq(gen));
    return loc;
}
