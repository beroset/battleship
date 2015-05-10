#ifndef BOMBER_H
#define BOMBER_H
#include "Ocean.h"

/*
 * plays the game with copy of passed Ocean
 */
class Bomber
{
public:
    Bomber(Ocean &o) : ocean(o), tracking(), turns(), verbose(false) {}
    virtual ~Bomber() = default;
    virtual bool turn() = 0;
    unsigned play() { while(turn()); return turns; }
protected:
    Ocean ocean;
    Ocean tracking;
    unsigned turns;
    bool verbose;
};
#endif // BOMBER_H
