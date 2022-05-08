#ifndef MENU_H
#define MENU_H
#include "GamePvP.h"
#define MENUMIDDLE 32 //how many chars are the radius of the big MENU printed
using namespace std;
class Menu{
public:
    void init(); //Launches the menu and also the whole program loop
    void printOptions() const; //Prints the menu screen with options for the player to pick from
    int getState(){
        return state;
    }
    void printInstructions(); //Prints instructions
    int getMenuInput() const;
private:
    int state;
    static vector<string> MENU; //Holds MENU written out to be printed over 7 lines
    void printMENU() const; //prints this MENU text
};
#endif