#ifndef allIncludes_H
#define allIncludes_H
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Stack portion
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

//validate portion
bool validateExpression(const std::vector<std::string>& tokens);
bool isOperator(const std::string& token);
bool isNumber(const std::string& token);

//evaluate portion
class ExpressionEvaluator {
public:
	double evaluateExpression(const vector<string>& expression);
	vector<string> convertToPostfix(const vector<string>& tokens);

	// Main method to evaluate a string expression by tokenizing, converting to postfix, and then evaluating need to implement once tokenizing is made
	// static double evaluate(const std::string& expression);
};
#endif
