#include "pieces.hpp"

BoardData board;

class Piece {
public:
	/* 0 is white, 1 is black */
	bool colour;
	Bitboard positions;
};

class rook: public Piece {
	void updateBoard() {
		board.attacking.set(1,2,true);
	}
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
