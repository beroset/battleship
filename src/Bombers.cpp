#include <vector>
#include "Bombers.h"
#include "RandomBomber.h"
#include "SmartRandom.h"
#include "SmarterRandom.h"

static RandomBomber rb{};
static SmartRandom sr{};
static SmarterRandom smr{};

std::vector<Bomber *> bombers{
    &rb, &sr, &smr
};
