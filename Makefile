CFLAGS = -O
CC = g++

SRCDIR = src

ctengine: main.o uci.o
	$(CC) $(CFLAGS)	-o	ctengine main.o uci.o

main.o:	${SRCDIR}/main.cpp
	$(CC) $(CFLAG)	-c ${SRCDIR}/main.cpp

uci.o:	${SRCDIR}/spec/uci.cpp
	$(CC) $(CFLAG)	-c ${SRCDIR}/spec/uci.cpp

clean:
	rm -fr core *.o