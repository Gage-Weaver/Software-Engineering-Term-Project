#include <iostream>

using namespace std;

//incorrect number of parenthesis case (too many open or closed parenthesis)
void invalidParenthesis(){
    //Prints the following explanation to the user, explaining why their expression with parenthesis included did not compute an answer
    cout << "Error: Imbalance of parenthesis. There are not an equal number of open and closing parenthesis. Check to ensure each opening parenthesis has a corresponding closing parenthesis." << endl;
}

//divide by 0 case
void divideByZero(){
     //Prints the following explanation to the user, explaining why their division didn't compute a solution
    cout << "Error: Divide by Zero. The divisor can't be zero." << endl;
}

//modulo by 0 case
void moduloByZero(){
    //prints the following explanation to the user, telling them why their modulo wasn't calculated
    cout << "Error: Modulo by Zero. The modulo operation can't be done with 0 as the divisor." << endl; 
}

/*
int main(){ //main function that runs each of the functions above as a test to prove they are outputting properly. It is commented out, as it's not necessary for full integration
    invalidParenthesis();
    divideByZero();
    moduloByZero();
}
*/
