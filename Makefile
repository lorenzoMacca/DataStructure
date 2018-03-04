PROG = app
CC = g++
AR = ar
CPPFLAGS = -g -Wall
LDFLAGS =
BIN = ./bin
OBJ = ./obj
INC = ./inc
INC_PATH = -I $(INC)
INC_LIB = -L $(LIB)
LIB = ./lib
DATA_STRUCTURE_LIB_NAME = dataStructure
DATA_STRUCTURE_LIB = lib$(DATA_STRUCTURE_LIB_NAME).a

# list of the objects which should be compiled for the lib
#
OBJS = Node.o List.o IteratorList.o Algorithms.o

# list of the objects + folder obj which should be compiled for app
#
LIST_OBJS=$(addprefix $(OBJ)/, $(OBJS))

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: $(PROG)

$(PROG) : $(DATA_STRUCTURE_LIB) $(OBJ)/main.o
		$(CC) $(LDFLAGS) -o $(BIN)/$(PROG) $(OBJ)/main.o $(INC_LIB) -l $(DATA_STRUCTURE_LIB_NAME)

$(OBJ)/main.o: src/main.cpp 
	$(CC) $(INC_PATH) $(CPPFLAGS) -c $< -o $@
	
$(OBJ)/Algorithms.o: src/Algorithms.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ)/List.o: src/List.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ)/IteratorList.o: src/IteratorList.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ)/Node.o: src/Node.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

create_lib: $(DATA_STRUCTURE_LIB)
	@echo $(DATA_STRUCTURE_LIB) has been compiled.

$(DATA_STRUCTURE_LIB): $(LIST_OBJS)
	@echo Compiling $(DATA_STRUCTURE_LIB)  
	$(AR) -r $(LIB)/$(DATA_STRUCTURE_LIB) $(LIST_OBJS)

clean:
		rm -drf $(BIN) $(OBJ) $(LIB) *.o $(INC)/*.gch *~ export_lib
		
# $@  is the name of the file being generated
# $<  the first prerequisite (usually the source file)
