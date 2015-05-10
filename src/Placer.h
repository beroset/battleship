#ifndef PLACER_H
#define PLACER_H

#include "Ocean.h"
#include <vector>
#include <string>

class Placer {
public:
    Placer() = default;
    virtual ~Placer() = default;
    virtual Ocean operator()() = 0;
    virtual const char *id() const = 0;
private:
};
extern std::vector<Placer *> placers;

#endif // PLACER_H
