PROG = app
CC = g++
CPPFLAGS = -g -Wall
LDFLAGS =
OBJS = main.o Node.o List.o Iterator.o

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: $(PROG)

$(PROG) : $(OBJS)
		$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

main.o: src/main.cpp inc/Node.h
	$(CC) $(CPPFLAGS) -c src/main.cpp inc/Node.h inc/TypeFoo.h

List.o: inc/List.h src/List.cpp inc/Node.h inc/Object.h inc/Iterator.h
	$(CC) $(CPPFLAGS) -c src/List.cpp

Iterator.o: inc/Iterator.h src/Iterator.cpp inc/Node.h inc/Object.h 
	$(CC) $(CPPFLAGS) -c src/Iterator.cpp

Node.o: inc/Node.h src/Node.cpp inc/Object.h
	$(CC) $(CPPFLAGS) -c src/Node.cpp

clean:
		rm -f $(PROG) *.o *.gch *~
