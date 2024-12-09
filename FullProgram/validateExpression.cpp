#include "allIncludes.h"
// Function to validate the expression
bool validateExpression(const std::vector<std::string>& tokens) {
	Stack parenthesesStack; //initialize our stack

	if (tokens.empty()) { //if there are no tokens passed then the expression is invalid
		std::cout << "Empty Expression" << std::endl;
		return false;
	}

	//if the first token is an operator that is not + or - it is immediately invalid along with a check to see that the - and + are followed by a number or parentheses
	if (isOperator(tokens[0]) && !((tokens[0] == "-" || tokens[0] == "+") && (isNumber(tokens[1]) || tokens[1] == "("))) {
		std::cout << "First token was an operator that is not + or -" << std::endl;
		return false;
	}

	if (isOperator(tokens[tokens.size() - 1])) { //ifthe last token is an operator the expression is immediately invalid
		std::cout << "Last token of the expression was an operator" << std::endl;
		return false;
	}

	bool lastWasNum = false; //boolean to keep track of if the last token was a number
	bool lastWasParen = false; //boolean to keep track of if the last token was a parentheses

	for (int i = 0; i < tokens.size(); i++) { //iterate through the tokens
		const std::string& token = tokens[i]; //set token variable equal to current token

		if (isNumber(token)) { //if the token is a number
			if (lastWasNum && !lastWasParen) { //if the last token was a number and the last token was not a parentheses it means two consecutive number tokens which is invalid
				std::cout << "Too many Consecutive number tokens: " << token << std::endl;
				return false;
			}
			lastWasNum = true; //otherwise just set lastWasNum to true
		} else if (isOperator(token)) { //if the token is an operator
			if (token != "-" && token != "+" && !lastWasNum) { //if the token is an operator excluding + and - and the last token was not a number it is invalid
				std::cout << "Consecutive operators error: " << token << std::endl;
				return false;
			}
			if (lastWasParen && !lastWasNum && token != "-" && token != "+") { //if the last token was an opening parentheses and the current token is not + or - it is invalid
				std::cout << "Invalid operator after parentheses: " << token << std::endl;
				return false;
			}
			lastWasNum = false; //otherwise just set lastWasNum to false
		} else if (token == "(") {
			if (lastWasNum) { //if the current token is an opening parentheses and last token was a number it is invalid (implicit multiplication not expected to be handled)
				std::cout << "Opening parentheses without an operator before" << std::endl;
				return false;
			}
			parenthesesStack.push(token); //push the opening parentheses onto our parentheses stack
			lastWasNum = false; //set lastWasNum to false (as a number/more parentheses/ or negation/add operator should follow this not other operators)
			lastWasParen = true; //set lastWasParen to true
		} else if (token == ")") {
			if (parenthesesStack.isEmpty()) { //if the token is a closing parentheses without an opening parentheses it is invalid
				std::cout << "Mismatched parentheses: too many closing parentheses." << std::endl;
				return false;
			}
			if (!lastWasNum) { //if the last token was an operator the parentheses cannot be closed
				std::cout << "Closing parentheses after an operator" << std::endl;
				return false;
			}
			parenthesesStack.pop(); //pop from the parentheses stack
			lastWasNum = true; //set lastWasNum to true as an operator should follow this not a number
			lastWasParen = true; //set lastWasParen to true
		} else { //if the token was not caught above at all it is an unrecognized token, return false
			std::cout << "Invalid character: " << token << std::endl;
			return false;
		}
	}

	if (!parenthesesStack.isEmpty()) { //check to see if the stack is not empty, return false if so as there was unclosed parentheses
		std::cout << "Mismatched parentheses: too many opening parentheses." << std::endl;
		return false;
	}
	return true;
}
