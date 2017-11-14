PROG = app
CC = g++
CPPFLAGS = -g -Wall

main.o: 

node.o: inc/Node.h src/Node.cpp inc/Object.h
	$(CC) $(CPPFLAGS) -c src/Node.cpp

clean:
		rm -f $(PROG) *.o *.gch *~
