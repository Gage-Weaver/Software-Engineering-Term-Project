#include fullbackend.h
using namespace std;

class backend //Create all encompassing backend class.
{
    public:
        int backendEvaluate(string input, vector<string> &output){ //Function that takes in string and initialize temp output
            ExpressionEvaluator evaluator; //Initialize expression evaluator class
            tokenizeExpression(input, output); //Call tokenize expression function
            evaluator.evaluateExpression(output); //Call evaluateExpression function
            return 0;
        }
};