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

class BitBoard {
private:
    std::bitset<64> board;
	void initalise ();
public:
    auto operator () (int x, int y){
        assert( 0 <= x && x <= 7);
        assert( 0 <= y && y <=7);
        return board [ 8 * y + x ];
    }
	auto output (int x, int y);
	auto innerIterator (int x, int y);
	auto outerIterator (int x, int y);
};
