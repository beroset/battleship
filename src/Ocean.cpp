#include "Ocean.h"
#include <cassert>
#include <iomanip>
#include <sstream>
#include <numeric>

constexpr Ship Ocean::navy[];

char Ocean::bomb(unsigned pos)
{
    assert(!oob(pos));
    int s = squares[pos];
    if (s) {
        squares[pos] = 0;
        return --ships[s-1] ? hit : navy[s-1].name[0];
    } else {
        return empty;
    }
}

void Ocean::record(unsigned pos, unsigned shiptype)
{
    assert(!oob(pos));
    squares[pos] = shiptype;
}

bool Ocean::place(unsigned pos, unsigned shiptype, bool horizontal, bool test)
{
    if (oob(pos) || shiptype >= shipcount)
        return false;
    int len = navy[shiptype].len;
    int delta = horizontal ? 1 : dim;
    if (oob(pos + len*delta))
        return false;
    // don't allow horizontal "wraparound"
    if (horizontal && ((pos % dim) + len >= dim))
        return false;
    bool occupied = false;
    // see if all spaces are available
    for (int d=0; d < len*delta; d += delta)
        occupied |= squares[pos+d];
    if (!occupied && !test) {
        // OK to place the ship
        ships[shiptype] = len;
        char ch = shiptype+1;
        for ( ; len; --len, pos+=delta)  {
            squares[pos] = ch;
        }
    }
    return !occupied;
}

/*
 * returns a string containing the current status of all ships.
 */
std::string Ocean::status() const
{
    std::stringstream status;
    for (int i = 0; i < shipcount; ++i) {
        status << std::setw(20) << navy[i].name <<
            "  " << ships[i] << '/' << navy[i].len << '\n';
    }
    return status.str();
}

unsigned Ocean::remaining() const { 
    return std::accumulate(ships.cbegin(), ships.cend(), 0);
}
