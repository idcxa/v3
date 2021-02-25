#include "iostream"

#include "position.hpp"

using namespace std;

void bitscan() {
    Bitboard test;

    test.set(5,5);
    test.board[5] = 1;
    for (std::size_t i = 0; i < test.board.size(); ++i) {
        std::cout << "test.board[" << i << "]: " << test.board[i] << '\n';
    }

    cout << "position.cpp" << endl;
}

