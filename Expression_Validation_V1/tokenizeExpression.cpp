/*
This file will be used to accept calculator input, tokenize it, then pass to the parser.
It will also ensure that adjacent values or expressions such as "55" or "**" will be properly interpreted
as "55" and the exponent operator, rather than "5", "5" and two multiplication operator.
Spaced and non-spaced expressions function as intended
*/

#include <iostream>
#include <vector>
#include <cctype> //For isdigit

using namespace std;


/* 
 * Pass in an expression as a string, and returns a vector of strings to store the tokens.
 * This function will tokenize the expression and store the tokens in the vector.
 */
int tokenizeExpression(string expression, vector<string> &tokens)
{
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ')
        {
            continue;
        }
        else if (isdigit(expression[i]) || expression[i] == '.')
        {
            string number = "";
            bool hasDecimal = false;

            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.'))
            {
                if (expression[i] == '.')
                {
                    if (hasDecimal)
                    {
                        break; // If there is more than one decimal, break the loop
                    }
                    hasDecimal = true;
                }
                number += expression[i];
                i++;
            }
            tokens.push_back(number);
            i--; // to counter the extra increment in the while loop
        }
        else
        {
            string op(1, expression[i]);
            tokens.push_back(op);
        }
    }
    return 0;
}

// Commenting out the tests cases, but leaving for reference. They can be removed as needed.
// For example, the output of the first test case: "5 + 10 - 15 * 20 / 25"
// prints to console as ["5", "+", "10", "-", "15", "*", "20", "/", "25"].

/*

int testprintExpression(vector<string> tokens)
{
    cout << "[";
    for (size_t i = 0; i < tokens.size(); i++)
    {
        cout << "\"" << tokens[i] << "\"";
        if (i != tokens.size() - 1) // Add a comma except for the last element
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}

int main()
{
    string testexpression1 = "5 + 10 - 15 * 20 / 25";
    string testexpression2 = "5+10-15*20/25";
    string testexpression3 = "(5 + 10) - (15 * 20) / 25";
    string testexpression4 = "(5+10)-(15*20)/25";

    vector<string> tokens;

    tokenizeExpression(testexpression1, tokens);
    printf("Test 1, space separated\n");
    testprintExpression(tokens);

    tokens.clear();

    tokenizeExpression(testexpression2, tokens);
    printf("Test 2, non-space separated\n");
    testprintExpression(tokens);

    tokens.clear();

    tokenizeExpression(testexpression3, tokens);
    printf("Test 3, space separated with parentheses\n");
    testprintExpression(tokens);

    tokens.clear();

    tokenizeExpression(testexpression4, tokens);
    printf("Test 4, non-space separated with parentheses\n");
    testprintExpression(tokens);
    
    return 0;
}

*/
