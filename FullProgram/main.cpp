#include "UIInteraction.h"
#include "commandhandling.h"
#include <iostream>
#include "fullbackend.h"
using namespace std;

//takes the input from UIinteraction and calls 
//the assosiated fucntion from CommandHandling 

int main(){
    //cout <<"in main"<< endl; //debug
    
    UIInteraction ui;
    CommandHandling commHand;
    Backend backend;

    ui.startupMessage();

    while(true){
        //cout <<"in loop" << endl; //debug
        string input = ui.inputPrompt();
        
        //cout <<"got input"<< endl; //debug

        if(input == "help"){
            commHand.help();
        }
        else if(input == "exit"){
            commHand.exit();
            break;
        }
        else{
            vector<string> output;
            try {
                double result = backend.backendEvaluate(input, output);
                cout << "Result: " << result << endl;
            } 
            catch (const std::runtime_error& e) {
                cerr << e.what() << endl;
                continue;  
            }
    }
}
