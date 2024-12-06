/*
This file will be used to accept calculator input, tokenize it, then pass to the parser.
It will also ensure that adjacent values or expressions such as "55" or "**" will be properly interpreted
as "55" and the exponent operator, rather than "5", "5" and two multiplication operator.
Spaced and non-spaced expressions function as intended
*/

#include <iostream>
#include <vector>
#include <cctype> //For isdigit
#include "tokenizeExpression.h"

using namespace std;


/* 
 * Pass in an expression as a string, and returns a vector of strings to store the tokens.
 * This function will tokenize the expression and store the tokens in the vector.
 */
int tokenizeExpression(const string &expression, vector<string> &tokens) {
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            continue;
        } else if (isdigit(expression[i]) || expression[i] == '.') {
            string number = "";
            bool hasDecimal = false;

            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    if (hasDecimal) {
                        break;  // If there is more than one decimal, break the loop
                    }
                    hasDecimal = true;
                }
                number += expression[i];
                i++;
            }
            tokens.push_back(number);
            i--;  // to counter the extra increment in the while loop
        } else {
            string op(1, expression[i]);
            tokens.push_back(op);
        }
    }
    return 0;
}

