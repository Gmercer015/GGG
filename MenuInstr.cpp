#include <iostream>
#include <string.h>
#include <fstream>
///Extern functions to save file space, MessageNameSpace became to large of a file
void Instructions()
{
    std::string Temp;
    using namespace std;
    ifstream Instr("Instructions.txt");
    cout << " ";
    while(Instr >> Temp){
        if(Temp == "\\n") //if the reader finds a newline character
        {
            Temp = "\n"; //replace it with a new newline char(does not work alone when read in)
        }
        cout << Temp << " "; //print out each word plus a space
        }
    Instr.close(); //close file to prevent leaks
};

void Credits()
{
    std::string Temp;
    using namespace std;
    ifstream Credit("Credits.txt");
    cout << " ";
    while(Credit >> Temp){
        if(Temp == "\\n")
        {
            Temp = "\n";
        }
        cout << Temp << " ";
        }
    Credit.close(); //close file to prevent leaks
};
