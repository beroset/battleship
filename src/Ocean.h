#ifndef OCEAN_H
#define OCEAN_H

#include <iostream>
#include <string>
#include <array>

struct Ship
{
    const char *name;
    int len;
};

/*
 * The Ocean class represents the playing field.
 */
class Ocean
{
public:
    Ocean() : squares(), ships() {}
    void reset() { squares.fill(0); ships.fill(0); }
    /*
     * returns empty if empty,
     * hit if hit or the first letter of the ship if sunk
     */
    char bomb(unsigned pos);
    /*
     * places (or test-places) the given ship type according to passed
     * coordinates and orientation.
     *
     * For horizontal, coordinates are leftmost point
     * For vertical, coordinates are topmost point
     * Return true if placement was successful
     */
    bool place(unsigned pos, unsigned shiptype, bool horizontal, bool test=false);
    /*
     * records the passed shiptype at the given location.
     * Only bounds checking is done.
     */
    void record(unsigned pos, unsigned shiptype);
    unsigned operator[](int p) const { return squares[p]; }
    std::size_t size() const { return dim*dim; }
    friend std::ostream& operator<<(std::ostream& out, const Ocean &o) {
        auto i=o.dim;
        for (auto &sq : o.squares) {
            if (sq) {
                out << (sq <= o.shipcount ? o.navy[sq-1].name[0] : o.hit);
            } else {
                out << o.empty;
            }
            if (--i == 0) {
                out << '\n';
                i = o.dim;
            }
        }
        return out;
    }
    std::string status() const;
    unsigned remaining() const;
    static constexpr char empty = '.';
    static constexpr char hit = 'x';
    static constexpr int shipcount = 5;
    static constexpr int dim = 10;
    static constexpr Ship navy[shipcount] { 
     {"Aircraft carrier", 5 },
     {"Battleship",       4 },
     {"Cruiser",          3 },
     {"Submarine",        3 },
     {"Patrol boat",      2 }
    };
private:
    // functions
    // oob = Out Of Bounds -- returns true iff point is oob
    bool oob(unsigned index) const {
        return index >= squares.size();
    }
    // data
    std::array<char, dim*dim> squares;
    std::array<int, shipcount> ships;
};
#endif // OCEAN_H
