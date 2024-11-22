#include <string>
#include <vector>
#include <iostream>
/**
Expression Parsing Layer:
    Expression Parsing class contains the following methods:
    ● parseExpression(string expression): Takes the expression as a string from the user and will break it
        down into numbers and operators
    ● validateExpression(string expression): This method will ensure proper usage of parentheses and
        operators
    ● evaluateExpression(string expression): This will be called upon by parseExpression after splitting
        input and ensuring its validity to make calls to our operators following PEMDAS
 */

//The class have to be built for Parsing

//The below portion of the code is for the validateExpression function it is not yet implemented in a class based approached but will be modified in further stages of development to reflect those changes

//Define a function names isNumber which returns a boolean value if the token is a number
bool isNumber(const std::string& token) {
        for (char c : token) { // Iterate through each character in the passed token
            if (!(c>='0' && c<='9' || c=='.')) { //check if the character is not a decimal or digit
                return false; //return false if so
            }
        }
        return true; //if the upper false is not returned then the token is a number
    }
    
    //function checking if the token is an operator
bool isOperator(const std::string& token) {
    //this will just return true if the token is any one of our defined operators
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "**";
}

//Define a class for our stack implementation for keeping track of parentheses
class Stack {
private:
    std::string data[1000]; // Fixed-size array for simplicity
    int topIndex;          // Tracks the index of the top element

public:
    Stack() : topIndex(-1) {} // Initialize the stack as empty

    void push(const std::string& value) {
        if (topIndex < 999) {  // Ensure we don't exceed the array size
            data[++topIndex] = value;
        } else {
            std::cout << "Exceeded stack size, way too many parentheses" << std::endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            --topIndex;
        } else {
            std::cout << "Tried to pop from empty stack" << std::endl;
        }
    }

    std::string top() const {
        if (!isEmpty()) {
            return data[topIndex];
        } else {
            std::cout << "Tried to access value from empty stack" << std::endl;
            return ""; // Return an empty string for invalid access
        }
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};

//define our function validateExpression that will return a boolean value if an expression is valid or not
//the function will take in a vector (array) of tokens and return the result
bool validateExpression(const std::vector<std::string>& tokens) {
        Stack parenthesesStack;
        //if tokens vector is empty return false as its not valid
        if (tokens.empty()) {
            std::cout << "Empty Expression" << std::endl;
            return false; //empty expression should be invalid
        }
        
        //see if the function starts with an operator except for the minus/plus sign as this can start the expression so long as a number or opening paren follows it
        if (isOperator(tokens[0]) && !((tokens[0] == "-" || tokens[0] == "+") && (isNumber(tokens[1]) || tokens[1]=="("))) {
            std::cout << "first token was an operator that is not + or -" << std::endl;
            return false; // First token can't be an operator unless it's a minus/plus sign
        }
        
        //see if the function ends with an operator (not valid no matter what)
        if (isOperator(tokens[tokens.size() - 1])) {
            std::cout << "last token of the expression was an operator" << std::endl;
            return false; // Last token can't be an operator no matter what
        }
    
        bool lastWasNum = false; //bool to keep track if the last token was a number
        bool lastWasParen = false; //boolean to check if the last token was a parentheses
        
        /*
        Below will be a loop that will iterate through the tokens array and will use
        a stack based approach to see if the expression is valid
        */
        
        for (int i = 0; i < tokens.size(); i++) {
            const std::string& token = tokens[i];
            
            //check to see if the token is a number, if the last token was a number also the expression is invalid
            if (isNumber(token)) {
                if (lastWasNum && !lastWasParen)  {
                    std::cout << "consecutive number tokens" << token << std::endl;
                    return false;
                }
                lastWasNum = true;
            }
            
            /*
            Check to see if the token is an operator, the logic behind the return is as follows
            if the token is not a minus/plus sign and the last was not a number return false, this is because a minus/plus sign 
            can precede a number at the beginning of a statement, for example -5+8 or 5*-8
            */
            else if (isOperator(token)) {
                if (token != "-" && token != "+" && !lastWasNum) {
                    std::cout << "consecutive operators error: " << token << std::endl;
                    return false;
                }
                if (lastWasParen && !lastWasNum && token != "-" && token != "+") {
                    std::cout << "token was not minus or plus and last token was a parentheses, you can only apply a minus or plus sign to parentheses" << std::endl;
                    return false; //if opening parentheses was last and we use any operator that isnt minus should be false
                }
                lastWasNum = false;
            }
            
            else if (token=="(") {
                if (lastWasNum) {
                    std::cout << "opening parentheses without an operator before" << std::endl;
                    return false;
                }
                parenthesesStack.push(token); // Push `(` onto the stack
                lastWasNum = false;
                lastWasParen = true;
            }
            
            else if (token==")") {
                if (parenthesesStack.isEmpty()) {
                    std::cout << "Mismatched parentheses: too many closing parentheses." << std::endl;
                    return false;
                }
                if (!lastWasNum) {
                    std::cout << "Attempted to close a parentheses while the last character was an operator" << std::endl;
                    return false;
                }
                parenthesesStack.pop(); // Pop the matching `(` from the stack
                lastWasNum = true;
                lastWasParen = true;
            }
            else {
                std::cout << "invalid character: " << token << std::endl;
                return false;
            }
        }
        if (!parenthesesStack.isEmpty()) {
            std::cout << "Mismatched parentheses: too many opening parentheses." << std::endl;
            return false;
        }
        return true;
    }
//End of code for validation function

