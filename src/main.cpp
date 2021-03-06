/* http://wbec-ridderkerk.nl/html/UCIProtocol.html

   Description of the universal chess interface (UCI)    April 2004
================================================================

* The specification is independent of the operating system. For Windows,
  the engine is a normal exe file, either a console or "real" windows application.

* all communication is done via standard input and output with text commands,

* The engine should boot and wait for input from the GUI,
  the engine should wait for the "isready" or "setoption" command to set up its internal parameters
  as the boot process should be as quick as possible.

* the engine must always be able to process input from stdin, even while thinking.

* all command strings the engine receives will end with '\n',
  also all commands the GUI receives should end with '\n',
  Note: '\n' can be 0x0c or 0x0a0c or any combination depending on your OS.
  If you use Engine und GUI in the same OS this should be no problem if you cummunicate in text mode,
  but be aware of this when for example running a Linux engine in a Windows GUI.

* The engine will always be in forced mode which means it should never start calculating
  or pondering without receiving a "go" command first.

* Before the engine is asked to search on a position, there will always be a position command
  to tell the engine about the current position.

* by default all the opening book handling is done by the GUI,
  but there is an option for the engine to use its own book ("OwnBook" option, see below)

* if the engine or the GUI receives an unknown command or token it should just ignore it and try to
  parse the rest of the string.

* if the engine receives a command which is not supposed to come, for example "stop" when the engine is
  not calculating, it should also just ignore it.

*/

#include "iostream"
#include "fstream"

//#include "main.hpp"
#include "uci.hpp"
#include "pieces.hpp"

#define PROJECT_NAME "ChessTrainer.c++"

const char* startpos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

int main(int argc, char* argv[]) {
    /* IO service */

    /* Store position from FEN and moves in bitboards */

    /* Valid move finder */

    /* Search, decides which moves look most promising to calculate first */

    /* Evaluator */
	std::string fen;
	if (argc >= 2) {
		for (int i = 1; i <= argc-1; i++) {
			std::string tmp = argv[i];
			fen = fen + tmp + " ";
		}
	} else {
		fen = startpos;
	}
    Position::set(fen, "");

    std::cout << Position::bestmove() << std::endl;

    UCI::loop(argc, argv);

    std::cout << "hiiii izzy <3 welcome to" << PROJECT_NAME << std::endl;

    return 0;
}
