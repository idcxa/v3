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

enum BoardPositions : int {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    PL = 64,
    PF = 0
};

enum Pieces : char {
    p, n, b, r, q, k,
    P, N, B, R, Q, K,
};

namespace Position {
    void set(std::string FEN, std::string play);
}

class Bitboard {
private:
    void initalise ();
    std::bitset<64> board;
public:
    void set(int x, int y, bool n){
        assert( 0 <= x && x <= 7);
        assert( 0 <= y && y <=7);
        board [ 8 * y + x ] = n;
    }
    auto output (int x, int y);
    auto innerIterator (int x, int y);
    auto outerIterator (int x, int y);
};

/**
struct Pieces
{   // Define piece values & such here

    Bitboard positions;
    bool attacked, pinned, checking;
    const int value;
    const char * moves;

};

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
