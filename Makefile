CFLAGS = -O
CC = g++

SRCDIR = src

ctengine: main.o uci.o
<<<<<<< HEAD
	$(CC) $(CFLAGS)	-o ctengine main.o uci.o
=======
	$(CC) $(CFLAGS)	-o	ctengine main.o uci.o
>>>>>>> e818fe1c2c14575ecd17c8d38c9204c3be48c4e0

main.o:	${SRCDIR}/main.cpp
	$(CC) $(CFLAG)	-c ${SRCDIR}/main.cpp

uci.o:	${SRCDIR}/spec/uci.cpp
	$(CC) $(CFLAG)	-c ${SRCDIR}/spec/uci.cpp

clean:
	rm -rf core *.o
