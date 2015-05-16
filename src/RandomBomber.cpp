#include <iostream>
#include "RandomBomber.h"

unsigned RandomBomber::guess() {
    unsigned location;
    for (location = randSq(gen); tracking[location]; location = randSq(gen));
    return location;
}

void RandomBomber::result(unsigned location, char bombresult)
{
    tracking.record(location, bombresult);
}
