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
        } else if (expression[i] == '*' && i + 1 < expression.length() && expression[i + 1] == '*') {
            // If we find '**', treat it as a single token
            tokens.push_back("**");
            i++;  // Skip the next character because it's part of '**'
        } else {
            // Otherwise, treat the current character as an individual token (operator, etc.)
            string op(1, expression[i]);
            tokens.push_back(op);
        }
    }
    return 0;
}
