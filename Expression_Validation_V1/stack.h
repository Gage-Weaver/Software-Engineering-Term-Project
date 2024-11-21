#ifndef STACK_H
#define STACK_H

#include <string>
#include <iostream>

// Stack class definition
class Stack {
private:
    std::string data[1000]; // Fixed-size array for simplicity
    int topIndex;          // Tracks the index of the top element

public:
    Stack(); // Constructor

    void push(const std::string& value); //functioon for push
    void pop(); //function for pop
    std::string top() const; //function for top
    bool isEmpty() const; //function for checking emptiness
};

#endif
