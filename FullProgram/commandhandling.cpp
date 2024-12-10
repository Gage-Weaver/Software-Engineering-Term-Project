
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
    cout <<"-Division by Zero"<< std::endl;
    cout <<"-Missing Parenthesis"<< std::endl;
    cout <<"-Invalid Symbols"<< std::endl;
    cout <<"-Missing Operand/Operator"<< std::endl;
    cout <<"=========================================================================================="<<std::endl;
    cout << "Valid Expression Examples: "<< std::endl;
    cout <<"2 + 4"<< std::endl;
    cout <<"6 - (2 + 3) "<< std::endl;
    cout <<"15 * 2 / 3"<< std::endl;
    cout <<"2 ** 3" << std::endl;
    cout <<"4 * 3 - (3 + 2) % 2 - 1"<< std::endl;
    cout <<"(((2 + 4)))"<< std::endl;
    cout <<"=========================================================================================="<<std::endl;
    cout <<"Invalid Expression Examples: "<< std::endl;
    cout <<"4 / 0        < Division by Zero"<< std::endl;
    cout <<"(3 - 2       < Missing Parenthesis"<< std::endl;
    cout <<"13 & 2       < Invalid Symbol"<< std::endl;
    cout <<"4 x 2        < Invalis Sumbol"<< std::endl;
    cout <<"* 3 - 8      < Missing Operand"<< std::endl;
    cout <<"2 * ( 1 - )  < Missing Operand"<< std::endl;
    cout <<"3 (2 + 1)    < Missing Operator"<< std::endl;
    cout <<"=========================================================================================="<<std::endl;
}
