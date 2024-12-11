#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class cmd_handle //Initialize cmd_handle class
{
    public: //Set the functions to public functions
        void exit_program(){ //Initialize the exit program function
            exit(0); //Use C++ built in function "exit" to exit the whole program.
        }
        void help(){ //Initialize the help function
            cout<< "Sample User Help Text" <<endl; //Output sample text, will be edited later to produce a more in depth manual for the user.
        }
};
