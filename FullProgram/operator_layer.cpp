#include "operator_layer.h"
using namespace std;

double Operator::addition(double a, double b) {
    return a + b;
}

double Operator::subtraction(double a, double b) {
    return a - b;
}

double Operator::division(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return 0;
    }
    return a / b;
}

double Operator::multiplication(double a, double b) {
    return a * b;
}

double Operator::power_raise(double a, double b) {
    return pow(a, b);
}

double Operator::modulus_operator(double a, double b){
    return fmod(a, b);
}