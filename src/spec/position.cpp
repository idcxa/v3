#include "iostream"
#include "sstream"
#include "stdio.h"
#include "ctype.h"

#include "position.hpp"

using namespace std;

void Position::set(string FEN, string movelist) {

    char token;
    istringstream ss(FEN);

    char board[PL];

    ss >> std::noskipws;

    /* loop through FEN */
    int i = 0;
    string p = " pnbrqk PNBRQK ";
    while ((ss >> token) && !isspace(token)) {
        if (isdigit(token)) {
            for (int j = 0; j <= 7; j++) {
                board[j+i] = '.';
            }
            i += (token - 48);
        }

        else if (token == '/') {
            i -= 0;
        }

        else if (p.find(token)) {
            board[i] = token;
            i++;
        }

    }

    puts("\n");
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            printf("%c ", board[i*8 + j]);
        }
        printf("\n");
    }
}

