#include "iostream"
#include "bitset"
#include "cassert"
#include "cstdint"
#include "string"

namespace Position {
    void set(std::string FEN, std::string play);
    void validmoves();
    std::string bestmove();
}

class Bitboard {
private:
    void initalise ();
    std::bitset<64> positions;
public:
    void set(int x, int y, bool n) {
        assert(0 <= x && x <= 7);
        assert(0 <= y && y <=7);
        positions[8*y + x] = n;
    }
    bool output (int x, int y) {
	return positions[8*y + x];
    }
    auto innerIterator (int x, int y);
    auto outerIterator (int x, int y);
};

struct Castling {
    bool wk;
    bool wq;
    bool bk;
    bool bq;
};

struct BoardData {
    char piecepositions[64];
    char colour;
    Castling castling;
    std::string enpassant = "";
    int ply = 0;
    int movenumber = 0;

    Bitboard attacking;
    Bitboard checking;
    Bitboard pinning;
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
