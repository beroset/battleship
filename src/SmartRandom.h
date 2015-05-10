#ifndef SMARTRANDOM_H
#define SMARTRANDOM_H
#include "Ocean.h"
#include "Bomber.h"

class SmartRandom : public Bomber
{
public:
    SmartRandom() : Bomber(), next() {}
    SmartRandom(Ocean &o) : Bomber(o), next() {}
    bool turn();
    const char *id() const { return "SmartRandom"; }
private:
    // vector holding the next guesses
    std::vector<unsigned> next;
};

#endif // SMARTRANDOM_H
