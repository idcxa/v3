CC = g++
CFLAGS = -O

SRCDIR = src

ctengine: 	main.o uci.o position.o
		$(CC) $(CFLAGS)	-o ctengine main.o uci.o position.o

main.o:		${SRCDIR}/main.cpp
		$(CC) $(CFLAG)	-c ${SRCDIR}/main.cpp

uci.o:		${SRCDIR}/spec/uci.cpp
		$(CC) $(CFLAG)	-c ${SRCDIR}/spec/uci.cpp

position.o:	${SRCDIR}/spec/position.cpp
		$(CC) $(CFLAG)	-c ${SRCDIR}/spec/position.cpp

clean:
		rm -rf core *.o
