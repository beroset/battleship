#ifndef RANDOMBOMBER_H
#define RANDOMBOMBER_H
#include "Ocean.h"
#include "Bomber.h"

class RandomBomber : public Bomber
{
public:
    const char *id() const { return "RandomBomber"; }
    std::ostream& printTo(std::ostream &out) { return out << "\nTracking:\n" << tracking << std::endl; }
private:
    unsigned guess();
    void result(unsigned location, char bombresult);
    void reset() { tracking.reset(); }
protected:
    Ocean tracking;
};

#endif // RANDOMBOMBER_H
