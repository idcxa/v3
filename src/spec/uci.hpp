# pragma once

namespace UCI {
	
	class UCIData {
	public:
		void position(istringstream &is);
	private:
		void loop(int argc, char* argv[]);
	};
	
}
