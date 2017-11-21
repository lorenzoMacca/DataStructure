PROG = app
CC = g++
CPPFLAGS = -g -Wall
LDFLAGS =
BIN = ./bin
OBJ = ./obj
INC = ./inc

# list of the objects which should be compiled for app
#
OBJS = main.o Node.o List.o IteratorList.o Algorithms.o

# list of the objects + folder obj which should be compiled for app
#
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
	$(CC) $(CPPFLAGS) -c $< -o $@
	
$(OBJ)/Algorithms.o: src/Algorithms.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ)/List.o: src/List.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ)/IteratorList.o: src/IteratorList.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ)/Node.o: src/Node.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
		rm -drf $(BIN) $(OBJ) *.o $(INC)/*.gch *~
		
# $@  is the name of the file being generated
# $<  the first prerequisite (usually the source file)
