#include "iostream"
#include "sstream"
#include "stdio.h"
#include "ctype.h"

#include "position.hpp"

using namespace std;

BoardData board;

void Position::set(string FEN, string movelist) {

    char token;
    istringstream ss(FEN);

    board.checking.set(5,5, true);

    board.colour = 'b';

    ss >> std::noskipws;

    /* piece positions */
    int i = 0;
    string p = " pnbrqk PNBRQK ";
    while ((ss >> token) && !isspace(token)) {
        if (isdigit(token)) {
            for (int j = 0; j <= 7; j++) {
                board.piecepositions[j+i] = '1';
            }
            i += (token - 48);
        }

        else if (token == '/') {
            i -= 0;
        }

        else if (p.find(token)) {
            board.piecepositions[i] = token;
            i++;
        }
    }

    /* side to move */
    ss >> token;
    board.colour = token;
    ss >> token;

    /* castling */
    while ((ss >> token) && !isspace(token)) {
        if (token == 'K') {
            board.castling.wk = true;
        } else if (token == 'Q') {
            board.castling.wq = true;
        } else if (token == 'k') {
            board.castling.bk = true;
        } else if (token == 'q') {
            board.castling.bq = true;
        }
    }

    /* enpassant */
    while ((ss >> token) && !isspace(token)) {
        if (token == '-') {
            board.enpassant = "";
        } else {
            board.enpassant.push_back(token);
        }
    }

    /* halfmove */
    ss >> token;
    board.ply = token - 48;
    ss >> token;

    /* fullmove */
    ss >> token;
    board.movenumber = token - 48;


    //ss >> token;
    //cout << token;

    /* print board */
    if (board.colour == 'w')
        printf("\nWhite to move\n");
    else
        printf("\nBlack to move\n");

    printf("===============\n");
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            if (board.piecepositions[i*8 + j] == '1')
                printf(". ");
            else
                printf("%c ", board.piecepositions[i*8 + j]);
        }
        printf("\n");
    }
    printf("===============\n");
}

string Position::bestmove() {
    return "bestmove idk pondering cock";
}
