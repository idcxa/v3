#include "iostream"
#include "sstream"
#include "stdio.h"
#include "ctype.h"

#include "future"

#include "position.hpp"

using namespace std;

BoardData board;

void Position::validmoves() {
}

string bw = " pnbrqk PNBRQK ";
string black = "pnbrqk";
string white = "PNBRQK";

void rook(int rank, int file) {
    bool rankbreak = false;
    bool filebreak = false;
    for (int i = 0; i <= 7; i++) {
    	if (!rankbreak) {
    	    board.attacking.set(rank, i, true);
    	}
    	//board.attacking.set(i, file, true);
    	if (!black.find(board.piecepositions[rank*8 + i]) && board.colour == 'b') {
    	    if (i < file) {
    		for (int j = i-1; j >= 0; j--) {
    		    board.attacking.set(rank,j,false);
    		}
    	    } else if (i > file) {
    		board.attacking.set(rank,i,true);
    		rankbreak = true;
    	    }
    	}

    }
    //board.attacking.set(rank,file, false);
}

void bishop() {
}

void queen() {
}

void pawn() {
}

void king() {
}

void Position::set(string FEN, string movelist) {

    //board.attacking.set(5, 5, true);
    char token;
    istringstream ss(FEN);

    ss >> std::noskipws;

    /* piece positions */
    int i = 0;
    while ((ss >> token) && !isspace(token)) {
        if (isdigit(token)) {
	    for (int j = 0; j <= 7; j++)
                board.piecepositions[j+i] = '1';
            i += (token - 48);
        }
        else if (token == '/')
            i -= 0;
        else if (bw.find(token)) {
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

    /* pieces */
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            switch(board.piecepositions[i*8 + j]) {
    		  case 'R':
    		    rook(i, j);
    		    break;
    	    }
    	}
    }

    /* print board */
    if (board.colour == 'w') {
        printf("\nWhite to move\n");
    } else {
        printf("\nBlack to move\n");
    }

    printf("===============\n");
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
	       if (board.attacking.output(i,j) == true)
		      printf("x ");
	        else if (board.piecepositions[i*8 + j] == '1')
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
