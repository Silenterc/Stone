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
    while(true){
        cout << "\033[H\033[2J" << flush;   
        printOptions();
        switch(getMenuInput()){
            case 0: cout <<"Invalid input, please try again." << endl;
                    sleep(2);
                    break;
            case 1: {
                        GamePvP g;
                        g.play();
                        break;
            }
            case 2: {
                        GamePvP ai;
                        ai.play();
                        break;                
            }
            case 3: {
                        break;
            }
            case 4: printInstructions();
                    cout <<"Type in anything to return to the Menu." << endl;
                    string s ;
                    cin >> s;
                    break;
        }
   
   
    }

}
void Menu::printInstructions(){
    ifstream instructions = loadFile("assets/instructions");
    cout << "\033[H\033[2J" << flush; 
    cout << instructions.rdbuf() << endl;
}
void Menu::printOptions() const{
    printMENU();
    printLines(6);
    cout <<"To play a PvP Game, type in 1" << endl;
    printLines(6);
    cout <<"To play a Game against an AI, type in 2" << endl;
    printLines(6);
    cout <<"To load a Game, type in 3" << endl;
    printLines(6);
    cout <<"To view instructions, type in 4" << endl;
}
int Menu::getMenuInput() const{
    string in;
    cin >> in;
    int num;
    try{
        num = stoi(in);
    } catch(...){
        return 0;
    }
    if(num > 4 || num < 1){
        return 0;
    }
    return num;
}
