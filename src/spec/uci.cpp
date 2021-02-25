#include "iostream"
#include "cmath"

#include "sstream"
#include "string"

#include "uci.hpp"

using namespace std;
namespace {
	const char *startpos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

	void position(istringstream &is) {
		string token, fen;
		is >> token;

		if (token == "startpos") {
			fen = startpos;
			is >> token;
		} else if (token == "fen") {
			// while the token isn't anything about moves, 
			// keep adding the fen onto the stream
			while (is >> token && token != "moves") {
				fen += token + " ";
				cout << fen;
			};
		}

	}

}	/* end of namespace */

void UCI::loop (int argc, char* argv[]) {
	string cmd, token;

	for (auto i = 1; i < argc; ++i) {
		cmd += string(argv[i]) + " ";
	}

	do {
		getline(cin, cmd);

		istringstream is (cmd);
		is >> skipws >> token;

		if (token == "quit" || token == "stop") {
			break;
		} else if (token == "uci") { cout << "uciok" << endl; }
		else if (token == "isready") { cout << "readyok" << endl; }
		else if (token == "go") { cout << "square up nigga" << endl; }
		else if (token == "position") { /* printf("%s\n", cmd.c_str()); */ position(is); }

	} while (token != "quit");

}
