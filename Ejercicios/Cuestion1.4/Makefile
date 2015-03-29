PROGRAM1=Cuestion1_4_1
PROGRAM2=Cuestion1_4_2

# Declaration of variables
CC = g++
CC_FLAGS = -w -std=c++11

# File names
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
all: $(OBJECTS)
	$(CC) funciones.o main1.o -o $(PROGRAM1)
	$(CC) main2.o -o $(PROGRAM2)

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(PROGRAM1) $(PROGRAM2) $(OBJECTS) datos.txt
