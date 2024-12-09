#include "allIncludes.h"
#include "operator_layer.h"
/*
This file is responsible for evaluating expressions passed to it
it will take the tokenized expression and utilize the shunting yard algorithm
in order to change the expression into postfix notation, this is the notation
that will allow the program to evaluate expressions while respecting PEMDAS
this program will assume that the functions for the artithmetic operators will be handling errors
such as dividing by zero, modulus by zero, or fractional exponentiation of a negative number
*/

/*
Firstly will be defining the precedence of the operators in PEMDAS, this will be accomplished
by assigning a value to each of the operators, 1 for +,-, 2 for *,/,%, and 3 for **
*/

//This is declaring a function to see the precedence of an operator
int precedence(const string& op) {
	if (op == "+" || op == "-") return 1;
	if (op == "*" || op == "/" || op == "%") return 2;
	if (op == "**") return 3;
	return 0;
}

/*
The exponent operator is associative from right to left, which is the opposite of
the rest of the operators so it will need to have a function to check for that when
converting the expression to postfix
*/

//This is declaring a function named leftAssoc which checks for the associativity of an operator
bool leftAssoc(const string& Operator) {
	if (Operator=="**") {
		return false;
	}
	return true;
}

//define a function to evaluate the postfix representation of an expression
double evaluatePostfix(const std::vector<std::string>& postfix) { 
	Stack numbers;  // Stack for numbers
	for (const std::string& token : postfix) { //iterate through tokens in expression
		if (isNumber(token)) { //if the token is a number
			numbers.push(token); //push it to the numbers stack
		}
		else { //otherwise
			std::string bstring = numbers.top(); //assign the second number in operation to the top of numbers stack
			double b = std::stod(bstring); //convert it to a double
			numbers.pop(); //pop from stack
			std::string astring = numbers.top(); //assign the second number in operator to the new top of numbers stack
			double a = std::stod(astring); //convert it to a double
			numbers.pop(); //pop from the stack
            
			double result; //declare a double to hold the result
			//once interconnected with other programs need to properly call the operator functions defined in the other functions, these here for testing
			Operator op;
			if (token == "+") {
				result = op.addition(a,b);
			} else if (token == "-") {
				result = op.subtraction(a,b);
			} else if (token == "*") {
				result = op.multiplication(a,b);
			} else if (token == "/") {
				result = op.division(a,b);
			} else if (token == "%") {
				result = op.modulus_operator(a,b);  
			} else if (token == "**") {
				result = op.power_raise(a,b);  
			}

			numbers.push(std::to_string(result));  // Push the result back to the stack
		}
	}

	return std::stod(numbers.top());  // The result will be the only element in the stack
}

/*
The next portion of the program is responsible for converting the tokenized expression
into postfix notation, this will be done by utilizing the shunting yard algorithm
it will utilize our stack class which is defined in stack.cpp. This portion was
developed while directly referencing the shunting yard algorithm wikepedia article,
if there are any questions about this portion please refer to the wikepedia article
for the shunting yard algorithm
*/

std::vector<std::string> ExpressionEvaluator::convertToPostfix(const std::vector<std::string>& tokens) {

    /*
    Below is a function for processing the tokens from the direct infix notation
    what this function will do is detect if a + or - sign is used as a unary symbol
    and then push a 0 in before the symbol so will evaluate as 0+token or 0-token
    */
	std::vector<std::string> processedTokens;
	for (size_t i = 0; i < tokens.size(); ++i) {
		const std::string& token = tokens[i];

		// Detect unary '+' or '-' and add a '0' before it
		if ((token == "-" || token == "+") && (i == 0 || tokens[i - 1] == "(" || isOperator(tokens[i - 1]))) {
			processedTokens.push_back("0");  // Add `0` before unary operator
		}
		processedTokens.push_back(token);  // Add the token itself
	}

	std::vector<std::string> result; //declare a vector to hold the conversion
	Stack operatorStack;  // Declare a stack for operators

	for (const std::string& token : processedTokens) { //iterate through the processed tokens
		if (isNumber(token)) { //if the token is a number
			result.push_back(token); //push it to the result vector
		}
		else if (token == "(") { //if the token is an open paren
			operatorStack.push(token); //push the paren to the operator stack
		}
		else if (token == ")") { //if the token is a closed paren
			while (!operatorStack.isEmpty() && operatorStack.top() != "(") { //while the top of stack isnt the corresponding open paren
				result.push_back(operatorStack.top()); //push the top operator to the result vector
				operatorStack.pop(); //pop the moved operator
			}
			if (!operatorStack.isEmpty() && operatorStack.top() == "(") { //once the open paren is found
				operatorStack.pop(); //pop from the operator stack
			}
		}
		else if (isOperator(token)) { //if the token is an operator
		    /*
		    The below comparison looks complex but it is essentially just meant
		    to handle the right associativity of the exponent operator by pushing
		    in the correct order to the stack
		    */
            while (!operatorStack.isEmpty() && 
                ((leftAssoc(token) && precedence(operatorStack.top()) >= precedence(token)) ||
                (!leftAssoc(token) && precedence(operatorStack.top()) > precedence(token)))) {
            result.push_back(operatorStack.top());
            operatorStack.pop();
            }
        operatorStack.push(token);
        }
	}
	while (!operatorStack.isEmpty()) { //empty out the rest of the operators
		result.push_back(operatorStack.top());
		operatorStack.pop();
	}
	return result; //return the converted vector
}
//define the class function for evaluating an expression when the input is already tokenized
//this just uses functions defined in this file and returns the result
double ExpressionEvaluator::evaluateExpression(const std::vector<std::string>& tokens) {
	if (!validateExpression(tokens)) {
		throw std::invalid_argument("Invalid expression");
	}

	std::vector<std::string> postfix = convertToPostfix(tokens);  // Convert to postfix

	return evaluatePostfix(postfix);  // Evaluate the postfix expression using a function like evaluatePostfix
}