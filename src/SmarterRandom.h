#ifndef SMARTERRANDOM_H
#define SMARTERRANDOM_H
#include "Ocean.h"
#include "Bomber.h"

class SmarterRandom : public Bomber
{
public:
    const char *id() const { return "SmarterRandom"; }
    std::ostream& printTo(std::ostream &out) { return out << "\nTracking:\n" << tracking << std::endl; }
private:
    unsigned guess();
    void result(unsigned location, char bombresult);
    void reset() {next.clear(); tracking.reset(); }
    unsigned randLocation();
    bool isBadLocation(unsigned loc) const {
        unsigned col = loc % Ocean::dim;
        unsigned row = loc / Ocean::dim;
        if (col & 1) {
            return (row & 1);
        } 
        return !(row & 1);
    }
private:
    // vector holding the next guesses
    std::vector<unsigned> next;
    Ocean tracking;
};

#endif // SMARTERRANDOM_H
