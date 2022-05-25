#ifndef PLAYERLIVE
#define PLAYERLIVE
#include "Player.h"
/**
 * @brief An alive Player whose actions are controlled by terminal commands.
 * 
 */
class PlayerLive : public Player{
public:
    PlayerLive(const string& nm,int hlth) : Player(nm, hlth){};
    PlayerLive() = default;
    /**
     * @brief Get the user input, throws an exception for EOF
     * 
     * @return string input
     */
    string getInput() const;
    unique_ptr<Player> clonePtr() override;
    /**
     * @brief Performs a command specified by user input.
     * The main function for an alive Player. Allows him to attack, play, save and exit the Game.
     * Takes care of invalid input.
     * @param trgt Enemy Player
     * @return int 1= there is more to be played, 0=his Turn has ended
     */
    int executeTurn(unique_ptr<Player>& trgt) override;
    /**
     * @brief Prints a confirmation screen so the next Player can play and not see his Cards.
     * 
     */
    void printConfirmation() const override;
    /**
     * @brief Prints the Player and his Hand and Board onto the Screen
     * 
     * @param flag Tells me on which side of the Game he is on, so I can either print the Hand or leave it censored
     */
    void print(unsigned int flag) const override;
protected:
    
};
#endif