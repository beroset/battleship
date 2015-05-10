#include <iostream>
#include <string>
#include <random>
#include "Ocean.h"
#include "Bombers.h"
#include "Placer.h"

int main()
{
    static constexpr int trials{10};
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
                std::cout << b->play(o) << '\t';
            }
        }
        std::cout << std::endl;
    }
}
