#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include "algorithm"
#include <filesystem>
#define MENUMIDDLE 25 //how many chars are the radius of the big MENU printed
using namespace std;
class Menu{
public:
    void init(); //Launches the menu and also the whole program loop
    void printOptions() const; //Prints the menu screen with options for the player to pick from
    void printInstructions() const; //Prints instructions
    int getMenuInput() const;
    /**
     * @brief Opens the Menu resposible for loading SaveFiles. 
     */
    void fileMenu() const;

    /**
     * @brief Prints all available savefiles 
     * @param svs Preprocessed vector of all the files in the saves directory.
     */
    void printSaves(vector<filesystem::directory_entry> svs) const;

    /**
     * @brief Iterates through the /saves directory and saves all the files in a vector.
     * @return returns a sorted vector with the savefiles from the saves dir.
     */
    vector<filesystem::directory_entry> loadSaves() const;

    /**
     * @brief Is responsible for handling user input regarding choosing a Save File to load.
     * @return 0 if unsuccessful, otherwise the number the user has chosen
     */
    unsigned long saveInput() const;
    bool extractGameType(ifstream&) const;
private:
    static vector<string> MENU; //Holds MENU written out to be printed over 7 lines
    static filesystem::path savesPath;
    void printMENU() const; //prints this MENU text
};
#endif