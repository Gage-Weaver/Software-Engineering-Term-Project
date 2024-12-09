#include "CommandHandling.h"
#include <iostream>
using namespace std;


bool CommandHandling::exit(){
    cout << "Now Exiting. Goodbye!" << endl;
    return true;
}
void CommandHandling::help(){
    cout <<"HELP "<< std::endl;
    cout <<"=========================================================================================="<<std::endl;
    cout <<"The expression parser accepts numeric constants, parenthesis, and the following operators"<<std::endl;
    cout <<"Valid operators: "<< std::endl;
    cout <<"(+)  Addition"<< std::endl;
    cout <<"(-)  Subtraction"<< std::endl;
    cout <<"(*)  Multiplication"<< std::endl;
    cout <<"(/)  Division"<< std::endl;
    cout <<"(%)  Modulo"<< std::endl;
    cout <<"(**) Exponentation"<< std::endl;
    cout <<"=========================================================================================="<<std::endl;
    cout <<"Common Errors to Avoid: "<< std::endl;
    cout <<  "-Division by zero" << std::endl;
    cout <<  "-Missing parenthesis" << std::endl;
    cout <<  "-Invalid symbols" << std::endl;
    cout <<"=========================================================================================="<<std::endl;
    cout << "Valid expression examples: "<< std::endl;
    //examples here
    cout <<"Invalid expression examples: "<< std::endl;
    //examples here
    cout <<"=========================================================================================="<<std::endl;
}