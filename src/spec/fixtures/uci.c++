#include "iostream"
#include "sstream"
#include "string"

#include "uci.hpp"

using namespace std;
void UCI::loop (int argc, char* argv[]) {
	string cmd, token;

	for (int i = 1; i < argc; ++i) {
		cmd += string(argv[i]) + " ";
	}

	do {
		istringstream is (cmd);
		is >> skipws >> token;

		if (token == "quit" || token == "stop") {
			break;
		}

	} while (token == "quit");
}

