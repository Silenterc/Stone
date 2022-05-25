#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Hand.h"
#include "PlayingBoard.h"
#include <limits>
#include <climits>
#include <sstream>
#include <fstream>
#include <iomanip>
/**
 * @brief Class representing a Player.
 * 
 */
class Player : public Entity{
public:
    Player(const string& nm,int hlth):Entity(nm,hlth){};
    Player() = default;
    /**
     * @brief Player draws a Card(from his Deck to his Hand)
     * 
     * @return pair<string, bool> Name of Card and bool whether the Card was succesfully drawn
     */
    pair<string, bool> drawCard(){
        return hand.drawCard(deck);    
    }
    void setDeck(Deck& d){
        deck = d;
    }
    /**
     * @brief Make all Cards on his Board charged( so they can attack)
     * 
     */
    void chargeBoard();
    /**
     * @brief Add change to the health of all Cards on the Player's board
     * 
     * @param change if it is +, then it adds health, if - then it damages
     */
    void dealDmgOrHealBoard(int change);
    size_t deckSize() const{
        return deck.getSize();
    }
    size_t boardSize() const{
        return board.getSize();
    }
    size_t handSize() const{
        return hand.getSize();
    }
    void printHand() const{
        hand.print();
    }
    void printBoard() const{
        board.print();
    }
    /**
     * @brief Prints Name,size of Deck and health in an order depending on flag
     * 
     * @param flag For symetrical purposes the info is printed in the opposite order between the 2 Players
     */
    void printInfo(unsigned int flag) const;
    PlayingBoard& getBoard(){
        return board;
    }
    /**
     * @brief Draws x amount of Cards
     * 
     * @param x amount of Cards to be drawn
     */
    void drawXCards(int x);
    /**
     * @brief calls deck.loadCards() to load them from the ifstream
     * 
     */
    void loadDeck(ifstream& in);
    /**
     * @brief Loads and sets Name, Health and Charged variables from the ifstream
     * 
     */
    void loadInfo(ifstream& in);
    void shuffleDeck(){
        deck.shuffle();
    }
    /**
     * Prints the Player info, Hand, Board.
     * If the flag is 0, then the Hand will be printed censored(using *).
     * 
     * @param flag 0 - enemy Player, 1 - allied Player
     */
    void print(unsigned int flag) const = 0; 
    /**
     * @brief Function to play a Card from his Hand to the Board
     * Returns false if the Board is full or the Player already played a Card that turn.
     * @param NO Index of the Card to be played(indexing from 1)
     * @param enemyPlayer Enemy Player& (for applying potential Battlecry effect)
     */
    bool playCard(unsigned long NO, Player& enemyPlayer); //returns false if the board is full.
    /**
     * @brief A complex function for performing an attack of a Card against an enemy Player
     * Checks for Taunts and charged status and updates the Board if the Card dies.
     * @param attacking Index of the Attacking Card (indexing from 1)
     * @param defending Index of the Defending Card (indexing from 1)
     * @param second Defending Player
     * @return true The attack was able to be performed
     * @return false Either there is a Taunt on the Board and I did not want to attack him, or I was not charged
     */
    bool attack(unsigned long attacking, unsigned long defending, Player& second); 
    /**
     * @brief Function to perform an attack of a Card against a Card on the enemy Board(cannnot attack enemy Player).
     * This function is used by AI when evaluating the best attack and then performing it.
     * @param attacking Index of the attacking Card (indexing from 1)
     * @param defending Index of the defending Card (indexing from 1)
     * @param second Enemy Player's Board
     */
    bool attack(unsigned long attacking, unsigned long defending, PlayingBoard& second);
    /**
     * @brief Prints all the Player's info into out
     * Prints the Player's basic info, Deck, Hand and Board
     * @param out 
     * @param p 
     * @return ostream& 
     */
    friend ostream& operator <<(ostream& out, const Player& p){
        p.printOstream(out);
        return out;
    }
    /**
     * @brief Loads all the Player's data from in
     * Loads the Player's basic info, Deck, Hand and Board
     */
    void load(ifstream& in);
    /**
     * @brief Checks if there is a Taunt card on the Player's Board
     * 
     * @return true There is a Taunt
     * @return false There is not a Taunt
     */
    bool hasTauntOnBoard() const;
    /**
     * @brief Ckecks whether the Player has any cards left
     * 
     * @return true He does
     * @return false He does not have any Cards in his Deck, Hand and on his Board
     */
    bool noCardsLeft() const;
    virtual unique_ptr<Player> clonePtr() = 0; 
    virtual int executeTurn(unique_ptr<Player>& trgt) = 0;
    virtual void printConfirmation() const = 0;
protected:
    /**
     * @brief The Player's Deck of Cards.
     * 
     */
    Deck deck;
    /**
     * @brief The Player's Hand. Each turn he can play a Card from his Hand.
     * 
     */
    Hand hand;
    /**
     * @brief The Player's Board. Each turn he can play a Card from his Hand onto the Board.
     * 
     */
    PlayingBoard board;
    void printOstream(ostream& out) const;
};
#endif