# pragma once

namespace UCI {
    void loop(int argc, char* argv[]);
    class UCIData{
        public:
        void position(std::istringstream &is);
    };
}
