#ifndef GAME
#define GAME
#include "PlayerLive.h"
#include "PlayerAI.h"
#define ENDMIDDLE 18
#define FIRSTTURNDRAW 3
#define SAVESPATH "assets/saves/"
#define CONFIGPATH "assets/config"
class Game{
public:
    Game(){};
    /**
     * @brief The Game loop.
     * This is the main function of the Game. The Players exchange turns, draw Cards, execute commands and 
     * the Game evaluates it's state. Once it's finished, this function ends.
     * @param justLoaded If the Game just loaded, then it continues the round instead of creating a new round
     */
    void play(bool justLoaded = false) ; //A complex function to play a new game
    /**
     * @brief Prints the current Game.
     * Prints both Players - Their Names, Health, Hands and Boards.
     */
    void printAll() const;
    /**
     * @brief Initializes the start of the Game.
     * Both Players load their info and decks from the config file and draw 3 Cards. 
     * @param PvP To know which Objects to construct as Players from loading the file. Either two PlayerLives or one and one AI.
     */
    void initStart(bool PvP);
    /**
     * @brief The Game evaluates who won, prints it and ends.
     * 
     */
    void finished() const;
    /**
     * This function generates a file and Saves the game in the predetermined format into it.
     * It writes the Game data (AI/PvP, playerTurn, isFirstRound) and calls both the Players's << operators,
     * which print the Players' data into the file.
     */
    void saveGame() const;
    /**
     * Loads the Game data (playerTurn, isFirstRound), constructs the correct Players
     * and lets them load their data.
     * @param PvP To know which Objects to construct as Players from loading the file. Either two PlayerLives or one and one AI.
     */
    void loadGame(ifstream& in, bool PvP);
    
protected:
    /**
     * @brief Prints a big END using ASCII art.
     */
    void printEnd() const;
    /**
     * @brief A specified Player draws a Card.
     * 
     * @param plr Which Player draws the card.
     */
    void drawsCard(bool plr);
    /**
     * @brief Changes the playerTurn bool.
     * 
     */
    void changePlayerTurn();
    /**
     * @brief Fills the Player smart pointers with the correct Objects(either two Live or one Live and one AI).
     * 
     */
    void initPlayers();
    /**
     * @brief Checks if both Players have nothing to play anymore.
     * 
     * @return true Both Players' decks, hand and boards are empty. 
     */
    bool noCardsLeft() const;
    /**
     * @brief Checks if some Player died.
     * 
     */
    bool someoneDied() const;
    /**
     * @brief Returns one of the two Players playing the Game depending on plr.
     * 
     * @param plr If true, returns player1, otherwise returns player2
     */
    unique_ptr<Player>& getPlayer(bool plr);
    static vector<string> END;
    /**
     * @brief First player.
     */
    unique_ptr<Player> player1;
    /**
     * @brief Second player.
     */
    unique_ptr<Player> player2;
    bool playerTurn = true; //1 for player1, 0 for player 2
    bool isDone = false;
    /**
     * This is an int because both Players have a first round => 2 first rounds.
     */
    int isFirstRound = 2;
    bool isPvP;
};
#endif