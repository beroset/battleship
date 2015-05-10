#include <iostream>
#include <string>
#include <random>
#include "Ocean.h"
#include "RandomBomber.h"
#include "Placer.h"

int main()
{
    static constexpr int trials{1000};
    std::cout << "There are " << placer.size() << " placers, and " 
        << 1 << " bombers\n";
    for (auto &p : placer) {
        Ocean o = p();
        std::cout << o.status() << o << std::endl;
        RandomBomber rb(o);
        std::cout << rb.play() << std::endl;
    }
}
