#include "iostream"
#include "sstream"

#include "position.hpp"

using namespace std;

void Position::set(string FEN, string play) {

    istringstream ss(FEN);
    string token;

    /* loop through FEN */
    while (ss >> token) {
        cout << token;
    }origin/testing
    cout << endl;
    Bitboard test;

    test.set(5,5,true);
    test.board[5] = 1;
    for (std::size_t i = 0; i < test.board.size(); ++i) {
        //std::cout << "test.board[" << i << "]: " << test.board[i] << '\n';
    }
    cout << "position.cpp" << endl;
}

