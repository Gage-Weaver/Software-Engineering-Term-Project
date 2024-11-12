/**
Operator Class contains the following methods:
    ● Addition(float a, float b): Adds two numbers.⁤ (a+b) and returns the answer
    ● Subtraction(float a, float b): Subtracts the second number from the first. (a-b) and returns the
        answer
    ● Multiplication(float a, float b): Multiplies two numbers.⁤ (a*b) and returns the answer
    ● Modulus(float a, float b): Returns the remainder of dividing the first number by the second number
        and returns the answer
    ● Divide(float a, float b): Returns the result of division, first number divided by second (a/b) and
        returns the answer with safeguards for division by 0
    ● Power(float a, float b): Computes the first integer to the power of the second and returns the
        answer
 */


#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
 


 class Operator{
    public:
        char history[10][10];
    
    char operation(float a,float b, char op){
        switch (op) {
        //  Addition
        case '+':
            cout << a << " + " << b << " = " << Caculator.addition(a, b) << endl;
            break;
        //   Subtraction
        case '-':
            cout << a << " - " << b << " = " << Caculator.subtraction(a, b) << endl;
            break;
        //    Multiplication
        case '*':
            cout << a << " * " << b << " = " << Caculator.multiplcation(a, b) << endl;
            break;
        //     Division
        case '/':
            cout << a << " / " << b << " = " << Caculator.division(a, b) << endl;
            break;
        //       Power
        case '**':
            cout << a << " ^ " << b << " = " << Caculator.power_raise(a, b) << endl;
            break;
        //       Invalid input handling 
        default:
            cout << "Invalid choice" << endl;
            cout << " TRY AGAIN"  << endl;
            break;
        }
    }
 
    float addition(float a, float b) {
        return a + b;
    }
    
    float subtraction(float a, float b) {
        return a - b;
    }
    
    float division(float a, float b) { 
        if (b == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
            return 0; 
        }
        return a/b; 
    }
    
    float multiplcation(float a, float b) {
        return a * b;
    }
    
    double power_raise(float a, float b) {
        return pow(a,b);
    }
};




int main() {
    float num_1;
    float num_2;
    char choice;
    Operator Caculator; 
    while (true){
        cout << "Enter a number: ";
        cin >> num_1;
        cout << endl;
        cout << "Enter operation to be performed (+, -, *, /, **): ";
        cin >> choice; // Read the choice from the user
        cout << endl;
        cout << "Enter another number: ";
        cin >> num_2;
        cout << endl;
        Caculator.operation(num_1, num_2, choice);
    }
    return 0 ; 
}
