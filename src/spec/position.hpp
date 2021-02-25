#include "iostream"
#include "bitset"
#include "cassert"
#include "cstdint"

/**	! Stuff we need	**
 *
 * 		checked
 *		attack-threat
 *		bitboards
 *
**/

namespace Position {
    void set();
}

class Bitboard {
private:
    void initalise ();
public:
    std::bitset<64> board;
    void set(int x, int y, bool n){
        assert( 0 <= x && x <= 7);
        assert( 0 <= y && y <=7);
        board [ 8 * y + x ] = n;
    }
    auto output (int x, int y);
    auto innerIterator (int x, int y);
    auto outerIterator (int x, int y);
};

typedef struct Pieces
{   // Define piece values & such here

    Bitboard positions;
    bool attacked, pinned, checking;
    const int value;
    const char * moves;

};

/**
- Another idea on how to implement pieces on the bitboard
    - The base class 'Pieces' holds all the base logic
    - and data that extend to all the other pieces
    -
    - those then get displayed and have their data mutated
    - through the separate logic functions

class Pieces {
public:
    Bitboard positions;
    bool attacked, pinned, checking;
    const int value;
    const char * moves;
    const int directions[];
}

class Rook : Pieces {

}
**/
