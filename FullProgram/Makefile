CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: Calculator

Calculator: main.cpp commandhandling.cpp evaluateExpression.cpp fullbackend.cpp operator_layer.cpp tokenizeExpression.cpp UIInteraction.cpp validateExpression.cpp validateHelpers.cpp stack.cpp
        $(CXX) $(CXXFLAGS) -o $@ $^

clean:
        rm -f Calculator


