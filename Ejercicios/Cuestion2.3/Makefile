PROGRAM=Cuestion2_3

# Declaration of variables
CC = g++
CC_FLAGS = -w

# File names
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM)

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(PROGRAM) $(OBJECTS)