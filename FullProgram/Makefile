
CXX = g++
CXXFLAGS = -std=c++17 -Wall -IFullProgram  

# Define directories
SRC_DIR = FullProgram
OBJ_DIR = obj  
BUILD_DIR = build

# add all cpp files as sources
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)


OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


EXEC = Calculator  # Change this to your desired executable name


all: $(EXEC)


$(EXEC): $(OBJECTS)
	$(CXX) -o $@ $^


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -rf $(OBJ_DIR) $(EXEC)


run: $(EXEC)
	./$(EXEC)
