#include <iostream>
#include <cmath>
using namespace std;
 
int addition(int a, int b) {
    return a + b;
}
 
int subtraction(int a, int b) {
    return a - b;
}
 
double division(int a, int b) { // Change return type to double for division
    if (b == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return 0; // Return 0 in case of division by zero
    }
    return static_cast<double>(a) / b; // Cast to double for accurate division
}
 
int multiplcation(int a, int b) {
    return a * b;
}
 
double power_raise(int a, int b) {
    return pow(a,b);
}
 
int main() {
    int num_1;
    int num_2;
    char choice;
     
    //  Perform the operation based infinitely
    while (true){
        cout << "Enter a number: ";
        cin >> num_1;
        cout << endl;
        cout << "Enter another number: ";
        cin >> num_2;
        cout << endl;
        cout << "Enter operation to be performed (+, -, *, /, ^): ";
        cin >> choice; // Read the choice from the user

        switch (choice) {
            //  Addition
            case '+':
                cout << num_1 << " + " << num_2 << " = " << addition(num_1, num_2) << endl;
                break;
            //   Subtraction
            case '-':
                cout << num_1 << " - " << num_2 << " = " << subtraction(num_1, num_2) << endl;
                break;
            //    Multiplication
            case '*':
                cout << num_1 << " * " << num_2 << " = " << multiplcation(num_1, num_2) << endl;
                break;
            //     Division
            case '/':
                cout << num_1 << " / " << num_2 << " = " << division(num_1, num_2) << endl;
                break;
            //       Power
            case '^':
                cout << num_1 << " ^ " << num_2 << " = " << power_raise(num_1, num_2) << endl;
                break;
            //       Invalid input handling 
            default:
                cout << "Invalid choice" << endl;
                cout << " TRY AGAIN"  << endl;
                break;
        }
    }
    return 0;
}