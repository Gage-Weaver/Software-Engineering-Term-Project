#include "allIncludes.h"
// Function to validate the expression
bool validateExpression(const std::vector<std::string>& tokens) {
	Stack parenthesesStack; //initialize our stack

	if (tokens.empty()) { //if there are no tokens passed then the expression is invalid
		throw runtime_error("Error: Empty Expression");
		return false;
	}

	//if the first token is an operator that is not + or - it is immediately invalid along with a check to see that the - and + are followed by a number or parentheses
	if (isOperator(tokens[0]) && !((tokens[0] == "-" || tokens[0] == "+") && (isNumber(tokens[1]) || tokens[1] == "("))) {
		throw runtime_error("Error: Cannot start expression with operator");
		return false;
	}

	if (isOperator(tokens[tokens.size() - 1])) { //ifthe last token is an operator the expression is immediately invalid
		throw runtime_error("Error: Last character cannot be an operator.");
		return false;
	}

	bool lastWasNum = false; //boolean to keep track of if the last token was a number
	bool lastWasParen = false; //boolean to keep track of if the last token was a parentheses

	for (int i = 0; i < tokens.size(); i++) { //iterate through the tokens
		const std::string& token = tokens[i]; //set token variable equal to current token

		if (isNumber(token)) { //if the token is a number
			if (lastWasNum && !lastWasParen) { //if the last token was a number and the last token was not a parentheses it means two consecutive number tokens which is invalid
				throw runtime_error("Error: Multiple numbers in a row");
				return false;
			}
			lastWasNum = true; //otherwise just set lastWasNum to true
		} else if (isOperator(token)) { //if the token is an operator
			if (token != "-" && token != "+" && !lastWasNum) { //if the token is an operator excluding + and - and the last token was not a number it is invalid
				throw runtime_error("Error: Consectutive Operators Error");
				return false;
			}
			if (lastWasParen && !lastWasNum && token != "-" && token != "+") { //if the last token was an opening parentheses and the current token is not + or - it is invalid
				throw runtime_error("Error: Operator directly after opening parentheses.");
				return false;
			}
			lastWasNum = false; //otherwise just set lastWasNum to false
		} else if (token == "(") {
			if (lastWasNum) { //if the current token is an opening parentheses and last token was a number it is invalid (implicit multiplication not expected to be handled)
				throw runtime_error("Error: Opening parentheses after a number (implicit multiplication not allowed)");
				return false;
			}
			parenthesesStack.push(token); //push the opening parentheses onto our parentheses stack
			lastWasNum = false; //set lastWasNum to false (as a number/more parentheses/ or negation/add operator should follow this not other operators)
			lastWasParen = true; //set lastWasParen to true
		} else if (token == ")") {
			if (parenthesesStack.isEmpty()) { //if the token is a closing parentheses without an opening parentheses it is invalid
				throw runtime_error("Error: Too many closing parentheses.");
				return false;
			}
			if (!lastWasNum) { //if the last token was an operator the parentheses cannot be closed
				throw runtime_error("Error: Closing Parentheses after an operator.");
				return false;
			}
			parenthesesStack.pop(); //pop from the parentheses stack
			lastWasNum = true; //set lastWasNum to true as an operator should follow this not a number
			lastWasParen = true; //set lastWasParen to true
		} else { //if the token was not caught above at all it is an unrecognized token, return false
			throw runtime_error("Error: Invalid Character in expression.");
			return false;
		}
	}

	if (!parenthesesStack.isEmpty()) { //check to see if the stack is not empty, return false if so as there was unclosed parentheses
		throw runtime_error("Error: Too many opening Parentheses.");
		return false;
	}
	return true;
}
