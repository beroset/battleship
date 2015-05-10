#ifndef RANDOMBOMBER_H
#define RANDOMBOMBER_H
#include "Ocean.h"
#include "Bomber.h"

class RandomBomber : public Bomber
{
public:
    RandomBomber() : Bomber() {}
    RandomBomber(Ocean &o) : Bomber(o) {}
    bool turn();
    const char *id() const { return "RandomBomber"; }
};

#endif // RANDOMBOMBER_H
