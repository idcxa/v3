#include "stdlib.h"
#include "iostream"
#include "cmath"
#include "sstream"
#include "string"
#include "cassert"

#include "uci.hpp"

#define VERS "0.1"

using namespace std;
namespace {

	const char* startpos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    void position(std::istringstream &is) {

        string token, fen;
        is >> token;

        if (token == "startpos") {
            fen = startpos;
            is >> token;
        } else if (token == "fen")
            // while the token isn't anything about moves,
            // keep adding the fen onto the stream
            while (is >> token && token != "moves")
                fen += token + " ";
        else
            return;

        cout << fen << endl;
    }
} // namespace


void UCI::loop (int argc, char* argv[]) {
    string cmd, token;

    for (int i = 1; i < argc; ++i) {
        cmd += string(argv[i]) + " ";
    }

    do {
        getline(cin, cmd);

        istringstream is (cmd);
        is >> skipws >> token;

        if (token == "quit" || token == "stop")
            break;
        else if (token == "uci")
            cout << "id name CTEngine " << VERS << endl
            << "id author Izzy Cassell\n"
            << "uciok" << endl;
        else if (token == "isready")
            cout << "readyok" << endl;
        else if (token == "position")
            position(is);
        else if (token == "go")
            cout << token << endl;


    } while (token != "quit");

}
