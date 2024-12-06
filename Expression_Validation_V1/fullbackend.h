#include "fullbackend.h"
//below is the function signature for backendEvaluate
int Backend::backendEvaluate(const std::string &input, std::vector<std::string> &output) {
    ExpressionEvaluator evaluator;  // Initialize expression evaluator
    tokenizeExpression(input, output);  // Tokenize the input string
    int result = evaluator.evaluateExpression(output);  // Evaluate the expression and store the result
    return result;  // Return the result
}
