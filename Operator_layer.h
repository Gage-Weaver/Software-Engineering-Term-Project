// Operator_layer.h

#ifndef OPERATOR_LAYER_H
#define OPERATOR_LAYER_H

class Operator {
public:
    // Method to perform the operation based on the operator provided
    double operation(double a, double b, char op);

    // Arithmetic operations
    double addition(double a, double b);
    double subtraction(double a, double b);
    double division(double a, double b);
    double multiplcation(double a, double b);
    double power_raise(double a, double b);
};

#endif // OPERATOR_LAYER_H