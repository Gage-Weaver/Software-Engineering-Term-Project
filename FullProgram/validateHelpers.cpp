#include "allIncludes.h"

// Function to check if the token is a number
bool isNumber(const std::string& token) {
	for (char c : token) {
		if (!(c >= '0' && c <= '9' || c == '.')) { //if the character is not a decimal or char between 0 and 9 return false
			return false;
		}
	}
	return true;
}

// Check if the token is an operator
bool isOperator(const std::string& token) {
	return token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "**";
}
