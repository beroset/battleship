#ifndef BOMBER_H
#define BOMBER_H
#include <iostream>
#include <random>
#include <algorithm>
#include "Ocean.h"

/*
 * plays the game with copy of passed Ocean
 */
class Bomber
{
public:
    virtual ~Bomber() = default;
    unsigned play(Ocean o) { 
        reset();
        unsigned osize = o.size();
        unsigned turns;
        for (turns = 0; o.remaining() && turns <= osize; ++turns)
        {
            unsigned location = guess();
            result(location, o.bomb(location));
            if (verbose)
                std::cout << "\nTurn " << turns << ", " << id() 
                    << " bombing " << location << '\n' 
                    << o 
                    << *this << std::endl;
        }
        return turns;
    }
    virtual const char *id() const = 0;
    friend std::ostream& operator<<(std::ostream &out, Bomber& b) {
        return b.printTo(out);
    }
    virtual std::ostream& printTo(std::ostream &out) { return out; }
    bool setVerbose(bool newvalue) { std::swap(newvalue, verbose); return newvalue; }
private:
    virtual unsigned guess() = 0;
    virtual void result(unsigned location, char bombresult) = 0;
    virtual void reset() {}
protected:
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> randSq{0, Ocean::dim*Ocean::dim-1};
    bool verbose = false;
};
#endif // BOMBER_H
