#include <iostream>

using namespace std;

void division(){ //function for division operation 
    float numerator, denominator, answer; //Defines the numerator, denominator, and answer as floats(decimal numbers) in order to handle non-whole number situations

    std::cout << "Numerator: "; //Prompts the user to enter an input for the numerator
    std::cin >> numerator; //Stores the value entered by the user as the float 'numerator' defined at the top of the function

    std::cout << "Denominator: "; //Prompts the user to enter an input for the denominator
    std::cin >> denominator; //Stores the value entered by the user as the float 'denominator' defined at the top of the function


    while (denominator == 0){ //while loop that runs as long as the denominator value entered is zero
        std::cout << "ERROR: The denominator value can't be zero for division operator. Enter a new denominator value: "; //print statement that explains the error of
        //divide by 0 and prompts the user to enter a new denominator value, giving the user a chance to fix the error without having to re-run the program
        std::cin >> denominator; //stores the new value entered by the user, which prompts the while loop to run again, confirming the new value they entered is valid before continuing 
    }

    answer = (numerator/denominator); //Defines the float 'answer' from the top of the function as the floating-point division of the numerator and denominator

    std::cout << "Answer: " << answer << std::endl; //Outputs the answer to the user 
}

int main(){ //main function
    division(); //single call to the division function. In the future this can be changed to a menu with a while loop in order to eliminate needing to rerun the program
}
