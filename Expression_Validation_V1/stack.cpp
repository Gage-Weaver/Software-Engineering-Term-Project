#include "allIncludes.h"
// Constructor to initialize the stack
Stack::Stack() : topIndex(-1) {}

// Push a value onto the stack
void Stack::push(const std::string& value) {
	if (topIndex < 999) { //capped at 1000 values
		data[++topIndex] = value; //set to the pushed value
	} else {
		std::cout << "Exceeded stack size, way too many parentheses" << std::endl; //if full stack output message
	}
}

// Pop a value from the stack
void Stack::pop() {
	if (!isEmpty()) { //if stack not empty go back an index
		--topIndex;
	} else {
		std::cout << "Tried to pop from empty stack" << std::endl; //if the stack is empty cannot pop
	}
}

// Get the top value from the stack
std::string Stack::top() const {
	if (!isEmpty()) { //if the stack isnt empty get the value at the top index
		return data[topIndex];
	} else {
		std::cout << "Tried to access value from empty stack" << std::endl; //output message that stack is empty
		return "";
	}
}

// Check if the stack is empty
bool Stack::isEmpty() const {
	return topIndex == -1; //Check if top index is -1 (meaning empty)
}