CXX = g++
CXXFLAGS = -O -std=c++2a -lstdc++ -fcoroutines-ts

SRCDIR = src

ctengine: 	main.o uci.o position.o
		$(CXX) $(CXXFLAGS)	-o ctengine main.o uci.o position.o

main.o:		${SRCDIR}/main.cpp
		$(CXX) $(CXXFLAGS)	-c ${SRCDIR}/main.cpp

uci.o:		${SRCDIR}/spec/uci.cpp
		$(CXX) $(CXXFLAGS)	-c ${SRCDIR}/spec/uci.cpp

position.o:	${SRCDIR}/spec/position.cpp
		$(CXX) $(CXXFLAGS)	-c ${SRCDIR}/spec/position.cpp

clean:
		rm -rf core *.o
