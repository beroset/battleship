#include <vector>
#include <random>
#include "Placer.h"
#include "Ocean.h"

static std::random_device rd;
static std::uniform_int_distribution<> r{0, Ocean::dim*Ocean::dim-1};
static std::bernoulli_distribution coin{0.5};

/*
 * crowd the ships into the upper left hand corner
 */
static Ocean upperleft() {
    Ocean o;
    for (int i=0; i < o.shipcount; ++i) {
        o.place(i, i, false);
    }
    return o;
}

/*
 * place the ships randomly
 */
static Ocean randomPlacer() {
    Ocean o;
    for (int i=0; i < o.shipcount; ++i) {
        for (unsigned loc = r(rd); !o.place(loc, i, coin(rd)); loc=r(rd));
    }
    return o;
}

std::vector<Ocean (*)()> placer{upperleft, randomPlacer};
