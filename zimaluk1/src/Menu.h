#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include <filesystem>
#define MENUMIDDLE 25 //how many chars are the radius of the big MENU printed
/**
 * @brief Responsible for printing the Menu and carrying out correlated tasks.
 * Prints options to play a PvP Game, PvAI Game, load a saved Game and view instructions.
 * Starts/loads the Games the user wants.
 */
class Menu{
public:
    void init(); //Launches the menu and also the whole program loop
    void printOptions() const; //Prints the menu screen with options for the player to pick from
    void printInstructions() const; //Prints instructions
    /**
     * @brief Gets the user input and detects invalid input.
     * 
     * @return int Identifier of what has the user chosen
     */
    int getMenuInput() const;
    /**
     * @brief Opens the Menu resposible for loading SaveFiles.
     * Prints the saveFiles in the saves folder and lets the user choose which one he wants to load. 
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
    /**
     * Extracts the first line from the ifstream and returns whether it is PvP or AI
     * or it throws an exception.
     */
    bool extractGameType(ifstream& in) const;
private:
    /**
     * @brief Holds MENU in ASCII art to be printed over 7 lines
     */
    static vector<string> MENU; 
    /**
     * @brief Path to the saves folder. 
     */
    static filesystem::path savesPath;
    /**
     * @brief prints the MENU text
     */
    void printMENU() const; 
};
#endif