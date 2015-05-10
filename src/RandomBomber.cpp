#include <iostream>
#include <string>
#include <random>
#include "RandomBomber.h"

static std::random_device rd;
static std::uniform_int_distribution<> r{0, Ocean::dim*Ocean::dim-1};

bool RandomBomber::turn() {
    ++turns;
    unsigned location;
    for (location = r(rd); tracking[location]; location = r(rd));
    tracking.record(location, ocean.bomb(location));
    if (verbose)
        std::cout << "Turn " << turns << ", bombing " << 
            location << '\n' << ocean << std::endl;
    return ocean.remaining();
}
