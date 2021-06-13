CXX = clang++
CXXFLAGS = -O -std=c++2a
#-lstdc++

SRCDIR = src

ctengine: 	main.o uci.o position.o
		$(CXX) $(CXXFLAGS)	-o ctengine main.o uci.o position.o

main.o:		${SRCDIR}/main.cpp
		$(CXX) $(CXXFLAGS)	-c ${SRCDIR}/main.cpp

uci.o:		${SRCDIR}/uci.cpp
		$(CXX) $(CXXFLAGS)	-c ${SRCDIR}/uci.cpp

position.o:	${SRCDIR}/position.cpp
		$(CXX) $(CXXFLAGS)	-c ${SRCDIR}/position.cpp

clean:
		rm -rf core *.o
