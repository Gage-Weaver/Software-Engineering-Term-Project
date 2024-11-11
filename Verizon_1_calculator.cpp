#include <iostream>
#include <cmath>
using namespace std;
 


 class Calculator{
    public:
        char history[10][10] = {}; 
 
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
 }

void operation(){
    
    float num_1;
    float num_2;
    char choice;
    Calculator operater; 
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
                cout << num_1 << " + " << num_2 << " = " << operater.addition(num_1,num_2) << endl;
                break;
            //   Subtraction
            case '-':
                cout << num_1 << " - " << num_2 << " = " << operater.subtraction(num_1, num_2) << endl;
                break;
            //    Multiplication
            case '*':
                cout << num_1 << " * " << num_2 << " = " << operater.multiplcation(num_1, num_2) << endl;
                break;
            //     Division
            case '/':
                cout << num_1 << " / " << num_2 << " = " << operater.division(num_1, num_2) << endl;
                break;
            //       Power
            case '^':
                cout << num_1 << " ^ " << num_2 << " = " << operater.power_raise(num_1, num_2) << endl;
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

int main() {
    operation();
    return 0 ; 
}
