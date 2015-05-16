#include <iostream>
#include "RandomBomber.h"

bool RandomBomber::turn() {
    ++turns;
    unsigned location;
    for (location = randSq(gen); tracking[location]; location = randSq(gen));
    tracking.record(location, ocean.bomb(location));
    if (verbose)
        std::cout << "Turn " << turns << ", bombing " << 
            location << '\n' << ocean << std::endl;
    return ocean.remaining();
}
