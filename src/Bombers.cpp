#include <vector>
#include "Bombers.h"
#include "RandomBomber.h"
#include "SmartRandom.h"

static RandomBomber rb{};
static SmartRandom sr{};

std::vector<Bomber *> bombers{
    &rb, &sr
};
