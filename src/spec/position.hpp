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

void bitscan();

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
