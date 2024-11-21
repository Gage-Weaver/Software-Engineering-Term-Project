#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class cmd_handle
{
    public:
        void exit_program(){
            exit(0);
        }
        void help(){
            cout<< "Sample User Help Text" <<endl;
        }
};