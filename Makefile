PROG = app
CC = g++
CPPFLAGS = -g -Wall
LDFLAGS =
BIN = ./bin
OBJ = ./obj

# list of the objects which should be compiled for app
OBJS = main.o Node.o List.o Iterator.o
LIST_OBJS=$(addprefix $(OBJ)/, $(OBJS))

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: $(PROG)

$(PROG) : $(LIST_OBJS)
		$(CC) $(LDFLAGS) -o $(BIN)/$(PROG) $(LIST_OBJS)

$(OBJ)/main.o: src/main.cpp 
	$(CC) $(CPPFLAGS) -c src/main.cpp -o $(OBJ)/main.o

$(OBJ)/List.o: src/List.cpp
	$(CC) $(CPPFLAGS) -c src/List.cpp -o $(OBJ)/List.o

$(OBJ)/Iterator.o: src/Iterator.cpp
	$(CC) $(CPPFLAGS) -c src/Iterator.cpp -o $(OBJ)/Iterator.o

$(OBJ)/Node.o: src/Node.cpp
	$(CC) $(CPPFLAGS) -c src/Node.cpp -o $(OBJ)/Node.o

clean:
		rm -drf $(BIN) $(OBJ) *.o *.gch *~
