#include "fullbackend.h"
#include "tokenizeExpression.cpp"
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
int main(){
    backend Backtest;
    vector<string> tokens;
    Backtest.backendEvaluate("3+4", tokens);
    return 0;
}
