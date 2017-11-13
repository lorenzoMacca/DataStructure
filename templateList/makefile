PROG = app
CC = g++
CPPFLAGS =
OBJS = main.o 

$(PROG) : $(OBJS)
		$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)


main.o: 
		$(CC) $(CPPFLAGS) -c main.cpp

clean:
		rm -f $(PROG) *.o *.gch *~



