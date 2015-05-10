#include <vector>
#include "Bombers.h"
#include "RandomBomber.h"

static RandomBomber rb{};

std::vector<Bomber *> bombers{
    &rb
};
