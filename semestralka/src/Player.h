#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Hand.h"
#include "Deck.h"
#include "PlayingBoard.h"
using namespace std;
class Player : public Entity{
public:
    Player(const string& nm,int hlth):Entity(nm,hlth){};
    pair<string, bool> drawCard(){
        return hand.drawCard(deck);
    }
    void setDeck(Deck& d){
        deck = d;
    }
    void printHand() const{
        hand.print();
    }
    void printBoard() const{
        board.print();
    }
    void print(unsigned int flag) const override; //if flag is zero, censor the hand, if it is 1, print it
    bool playCard(int NO){ //returns false if the board is full.
        return board.addToBoard(hand.playCard(NO));
    }
    void attack(int attacking, int defending, Player& second);
protected:
    Deck deck;
    Hand hand;
    PlayingBoard board;
};
#endif