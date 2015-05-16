#ifndef SMARTRANDOM_H
#define SMARTRANDOM_H
#include "Ocean.h"
#include "Bomber.h"

class SmartRandom : public Bomber
{
public:
    const char *id() const { return "SmartRandom"; }
    std::ostream& printTo(std::ostream &out) { return out << "\nTracking:\n" << tracking << std::endl; }
private:
    unsigned guess();
    void result(unsigned location, char bombresult);
    void reset() {next.clear(); tracking.reset(); }
private:
    // vector holding the next guesses
    std::vector<unsigned> next;
    Ocean tracking;
};

#endif // SMARTRANDOM_H
