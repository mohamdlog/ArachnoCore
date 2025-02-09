# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -I./include -Wall -Wextra -std=c++20

# Source files
SRC = $(shell find src -type f -name "*.cpp")

# Object files
OBJ = $(SRC:.cpp=.o)

# Output executable name
TARGET = ArachnoCore

# Default rule to build the program
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) -li2c

# Rule to compile each .cpp file into a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJ) $(TARGET)
