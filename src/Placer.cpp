#include <vector>
#include <random>
#include <string>
#include "Placer.h"
#include "Ocean.h"

static std::random_device rd;
static std::uniform_int_distribution<> r{0, Ocean::dim*Ocean::dim-1};
static std::bernoulli_distribution coin{0.5};

/*
 * crowd the ships into the upper left hand corner
 */
class UpperLeft : public Placer {
    Ocean operator()() {
        Ocean o;
        for (int i=0; i < o.shipcount; ++i) {
            o.place(i, i, false);
        }
        return o;
    }
    const char *id() const { return "UpperLeft"; }
};

/*
 * place the ships randomly
 */
class RandomPlacer : public Placer {
    Ocean operator()() {
        Ocean o;
        for (int i=0; i < o.shipcount; ++i) {
            for (unsigned loc = r(rd); !o.place(loc, i, coin(rd)); loc=r(rd));
        }
        return o;
    }
    const char *id() const { return "RandomPlacer"; }
};

static UpperLeft ul;
static RandomPlacer rp;


std::vector<Placer *> placers{&ul, &rp};
