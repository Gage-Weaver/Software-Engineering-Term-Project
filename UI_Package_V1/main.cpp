#include "UIInteraction.h"
#include "CommandHandling.h"
#include <iostream>
#include "fullbackend.h"
using namespace std;


int main(){
    
    UIInteraction ui;
    CommandHandling commHand;
    Backend backend;

    ui.startupMessage();

    while(true){
        string input = ui.inputPrompt();
        

        if(input == "help"){
            commHand.help();
        }
        else if(input == "exit"){
            commHand.exit();
            break;
        }
        else{
            vector<string> output;
            double result = backend.backendEvaluate(input, output);
            cout<<"Answer="<< result << endl; //debug
        }
    }
}
