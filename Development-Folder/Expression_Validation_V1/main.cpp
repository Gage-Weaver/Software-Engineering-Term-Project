#include "allIncludes.h"
using namespace std;

//Below is the main function used to test the module
int main() {
	ExpressionEvaluator evaluator;
	vector<pair<vector<string>, double>> testCases = {
		{{"3", "+", "4"}, 7.0}, 
		{{"8", "-", "(", "5", "-", "2", ")"}, 5.0}, 
		{{"10", "*", "2", "/", "5"}, 4.0}, 
		{{"2", "**", "3"}, 8.0}, 
		{{"4", "*", "(", "3", "+", "2", ")", "%", "7", "-", "1"}, 5.0}, 
		{{"(", "(", "(", "2", "+", "3", ")", ")", ")", "+", "(", "(", "(", "1", "+", "2", ")", ")", ")"}, 8.0}, 
		{{"(", "(", "5", "*", "2", ")", "-", "(", "(", "3", "/", "1", ")", "+", "(", "(", "4", "%", "3", ")", ")", ")", ")"}, 6.0}, 
		{{"(", "(", "(", "2", "**", "(", "1", "+", "1", ")", ")", "+", "(", "(", "3", "-", "1", ")", "**", "2", ")", ")", "/", "(", "(", "4", "/", "2", ")", "%", "3", ")", ")"}, 4.0},
		{{"(", "(", "(", "(", "(", "5", "-", "3", ")", ")", ")", "*", "(", "(", "(", "2", "+", "1", ")", ")", ")", "+", "(", "(", "2", "*", "3", ")", ")", ")", ")"}, 12.0}, 
		{{"(", "(", "9", "+", "6", ")", ")", "/", "(", "(", "3", "*", "1", ")", "/", "(", "(", "2", "+", "2", ")", ")", "-", "1", ")"}, -60.0}, 
		{{"+", "(", "-", "2", ")", "*", "(", "-", "3", ")", "-", "(", "(", "-", "4", ")", "/", "(", "+", "5", ")", ")"}, 6.8}, 
		{{"-", "(", "+", "1", ")", "+", "(", "+", "2", ")"}, 1.0}, 
		{{"-", "(", "-", "(", "-", "3", ")", ")", "+", "(", "-", "4", ")", "+", "(", "+", "5", ")"}, -2.0}, 
		{{"+", "2", "**", "(", "-", "3", ")"}, 0.125}, 
		{{"-", "(", "+", "2", ")", "*", "(", "+", "3", ")", "-", "(", "-", "4", ")", "/", "(", "-", "5", ")"}, -6.8}, 
		{{"2", "**", "2", "**", "3"}, 256.0},
		{{"(", "2", "**", "2", ")", "**", "3"}, 64.0}
	};
	for (const auto& testCase : testCases) {
		const vector<string>& tokens = testCase.first;
		double expected = testCase.second;

		try {
			double result = evaluator.evaluateExpression(tokens);
			if (result == expected) {
				cout << "Test Passed: ";
			} else {
				cout << "Test Failed: ";
			}
			cout << "Expression: ";
			for (const string& token : tokens) {
				cout << token << " ";
			}
			cout << "Expected: " << expected << " Result: " << result << endl;
		}
		catch (const invalid_argument& e) {
			cout << "Test Failed (Invalid Argument): " << e.what() << endl;
		}
		catch (const exception& e) {
			cout << "Test Failed (Other Error): " << e.what() << endl;
		}
	}

	return 0;
}
