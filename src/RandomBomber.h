#ifndef RANDOMBOMBER_H
#define RANDOMBOMBER_H
#include "Ocean.h"
#include "Bomber.h"

class RandomBomber : public Bomber
{
public:
    RandomBomber(Ocean &o) : Bomber(o) {}
    bool turn();
};

#endif // RANDOMBOMBER_H
