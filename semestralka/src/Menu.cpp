#include "Menu.h"
#include <iostream>
using namespace std;
vector<string> Menu::MENU = {{" I      I     I-------     I      I     I      I    "},
                             {" I \\  / I     I            I\\     I     I      I    "},
                             {" I  \\/  I     I            I \\    I     I      I    "},
                             {" I      I     I-------     I  \\   I     I      I    "},   
                             {" I      I     I            I   \\  I     I      I    "},
                             {" I      I     I            I    \\ I     \\      /     "},
                             {" I      I     I-------     I     \\I      \\____/      "},

};
void Menu::printMENU() const{
    for(const auto& row : MENU){
        printSpaces((getTermSize()/2) - MENUMIDDLE);
        for(const auto& col : row){
            cout << col;
        }
        cout << endl;
    }
}
void Menu::init(){
    cout << "\033[H\033[2J" << flush;
    printMENU();
    //printInstructions();

}
void Menu::printInstructions(){
    ifstream instructions = loadFile("assets/instructions");
    cout << instructions.rdbuf() << endl;
}
