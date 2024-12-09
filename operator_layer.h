#ifndef OPERATOR_LAYER_H
#define OPERATOR_LAYER_H
using namespace std;
#include <iostream>
#include <cmath>
class Operator {
public:
    // Method to perform the operation based on the operator provided
    double operation(double a, double b, char op);

    // Arithmetic operations
    double addition(double a, double b);
    double subtraction(double a, double b);
    double division(double a, double b);
    double multiplication(double a, double b);
    double power_raise(double a, double b);
    double modulus_operator(double a, double b);
};

#endif
