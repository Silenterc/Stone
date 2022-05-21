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
using namespace std;
class Player : public Entity{
public:
    Player(const string& nm,int hlth):Entity(nm,hlth){};
    Player() = default;
    pair<string, bool> drawCard(){
        return hand.drawCard(deck);    
    }
    void setDeck(Deck& d){
        deck = d;
    }
    void chargeBoard();
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
    void printInfo(unsigned int flag) const;
    PlayingBoard& getBoard(){
        return board;
    }
    void drawXCards(int x);
    void loadDeck(ifstream& in);
    void loadInfo(ifstream& in);
    void shuffleDeck(){
        deck.shuffle();
    }
    void print(unsigned int flag) const = 0; //if flag is zero, censor the hand, if it is 1, print it
    bool playCard(unsigned long NO, Player& enemyPlayer); //returns false if the board is full.
    bool attack(unsigned long attacking, unsigned long defending, Player& second); //a complex function for a player attacking another player with one of his cards
    bool attack(unsigned long attacking, unsigned long defending, PlayingBoard& second);
    friend ostream& operator <<(ostream& out, const Player& p){
        p.printOstream(out);
        return out;
    }
    void load(ifstream& in);
    bool hasTauntOnBoard() const;
    bool noCardsLeft() const;
    virtual unique_ptr<Player> clonePtr() = 0; 
    virtual int executeTurn(unique_ptr<Player>& trgt) = 0;
    virtual void printConfirmation() const = 0;
protected:
    Deck deck;
    Hand hand;
    PlayingBoard board;
    void printOstream(ostream& out) const;
};
#endif