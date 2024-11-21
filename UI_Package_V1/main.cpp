#include "UIInteraction.h"
#include "CommandHandling.h"
#include <iostream>
using namespace std;

//takes the input from UIinteraction and calls 
//the assosiated fucntion from CommandHandling 

int main(){
    //cout <<"in main"<< endl; //debug
    
    UIInteraction ui;
    CommandHandling commHand;

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
            //Assumes input is an expression
            //Send to backend here
            //ui.showResult(result);
            cout<<"Got expression"<<endl; //debug
        }
    }
}
