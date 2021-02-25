#include "iostream"
#include "cstdint"

namespace {
	class BitBoard {
	public:
		auto output (int x, int y);
		auto innerIterator (int x, int y);
		auto outerIterator (int x, int y);
	private:
		void initalise();
	};
}
