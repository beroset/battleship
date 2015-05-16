#ifndef BOMBER_H
#define BOMBER_H
#include <random>
#include "Ocean.h"

/*
 * plays the game with copy of passed Ocean
 */
class Bomber
{
public:
    Bomber() : ocean(), tracking(), turns(), verbose(false) 
    {}
    Bomber(Ocean &o) : ocean(o), tracking(), turns(), verbose(false) 
    {}
    virtual ~Bomber() = default;
    virtual bool turn() = 0;
    void reset(Ocean &o) { ocean=o; tracking=Ocean{}; turns=0; }
    unsigned play() { while(turn()); return turns; }
    unsigned play(Ocean &o) { reset(o); return play(); }
    virtual const char *id() const = 0;
protected:
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> randSq{0, Ocean::dim*Ocean::dim-1};
    Ocean ocean;
    Ocean tracking;
    unsigned turns;
    bool verbose;
};
#endif // BOMBER_H
