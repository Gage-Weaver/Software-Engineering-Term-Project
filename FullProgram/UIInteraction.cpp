#include "UIInteraction.h"
#include <iostream>
using namespace std;


void UIInteraction::startupMessage(){

    cout <<"=========================================================================================="<<std::endl;
    cout <<"Welcome to the arithmetic expression parser"<<std::endl;
    cout <<"To start, enter an expression, or type 'help' for a full list of instructions and tips." <<std::endl;
    cout <<"Type 'exit' when you're done." << std::endl; 
    cout <<"=========================================================================================="<<std::endl;

}

//constant input prompt/menu, loop running in main
string UIInteraction::inputPrompt(){

    cout <<"=========================================================================================="<<std::endl;
    cout <<"Type an expression to be parsed."<< std::endl;
    cout << std::endl;
    //cout <<"Type 'help' for more information"<< std::endl;
    //cout << std::endl;                                         //**Should we include help and exit in prompt?
    //cout <<"Type 'exit' when you're done."<< std::endl;
    cout << "> ";
    
    //take input and return it to main
    string input;
    getline(cin, input);
    cout << "User entered: " << input << endl; //test input, delete later
    return input;
}

//get result or error type from backend
void UIInteraction::showResult(float result){

cout<<"Parsed Expression: " << result << std::endl;

}
void UIInteraction::showError(string error){

cout << "Error: " << error << std::endl;
cout << "Please try again, or type 'help' for more instruction.";

}