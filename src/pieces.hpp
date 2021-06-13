#include "bitset"
#include "cassert"

namespace Position {
    void set(std::string FEN, std::string play);
    void validmoves();
    std::string bestmove();
}

class Bitboard {
private:
    void initalise ();
    std::bitset<64> board;
public:
    void set(int x, int y, bool n) {
        assert(0 <= x && x <= 7);
        assert(0 <= y && y <=7);
        board[8*y + x] = n;
    }
    bool output (int x, int y) {
	return board[8*y + x];
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

