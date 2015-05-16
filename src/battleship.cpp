#include <iostream>
#include <cstdlib>
#include "Ocean.h"
#include "Bombers.h"
#include "Placer.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "Usage: battleship trials [VERBOSE]\n";
        return 0;
    }

    static const int trials{std::atoi(argv[1])};
    bool verbose = false;
    if (argc > 2 && argv[2][0] == 'V')
        verbose = true;
    std::cerr << "There are " << placers.size() << " placers, and " 
        << bombers.size() << " bombers\nRunning " << trials 
        << " iterations\n";
    for (auto &p : placers) {
        for (auto &b : bombers) {
            std::cout << p->id() << "/" << b->id() << '\t';
        }
    }
    std::cout << std::endl;
    for (auto i=0; i < trials; ++i) {
        for (auto &p : placers) {
            Ocean o = (*p)();
            for (auto &b : bombers) {
                b->setVerbose(verbose);
                std::cout << b->play(o) << '\t';
            }
        }
        std::cout << std::endl;
    }
}
