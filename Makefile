# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -I./include -Wall -Wextra -std=c++17

# Source files
SRC = src/main.cpp src/PCA9685.cpp src/RobotConfig.cpp  

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
