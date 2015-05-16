#include <vector>
#include <random>
#include <string>
#include "Placer.h"
#include "Ocean.h"


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
            for (unsigned loc = randSq(gen); !o.place(loc, i, coin(gen)); loc=randSq(gen));
        }
        return o;
    }
    const char *id() const { return "RandomPlacer"; }
private:
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> randSq{0, Ocean::dim*Ocean::dim-1};
    std::bernoulli_distribution coin{0.5};
};

static UpperLeft ul;
static RandomPlacer rp;


std::vector<Placer *> placers{&ul, &rp};
