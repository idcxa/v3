# pragma once

namespace {
	typedef struct Pieces
	{	// Define piece values & such here
		bool attacked;
		bool pinned;

		struct Rook {
			const int value = 5;
			const char * moves = "nswe"; // north, south, west, east
		};

		struct Bishop {
			const int value = 3;
			const char * moves = "dr";	// diagonal
		};

		struct Knight {
			const int value = 3;
			const char * moves = "xor";	// knight moves like an xor
		};

		struct Queen {
			const int value = 9;
			const char * moves = "all_u";	// literally any direction, unlimited
		};
		struct King {
			const int value = 0;
			const char * moves = "all";	// all but not unlimited
		};
	};
};
