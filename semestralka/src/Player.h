#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Hand.h"
#include "Deck.h"
#include "PlayingBoard.h"
#include <sstream>
#include <iostream>
#include <fstream>
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
    void chargeBoard();
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
    PlayingBoard& getBoard(){
        return board;
    }
    void drawThreeCards();
    void loadDeck();
    void shuffleDeck(){
        deck.shuffle();
    }
    void print(unsigned int flag) const override; //if flag is zero, censor the hand, if it is 1, print it
    bool playCard(int NO); //returns false if the board is full.
    bool attack(int attacking, int defending, Player& second); //a complex function for a player attacking another player with one of his cards
protected:
    Deck deck;
    Hand hand;
    PlayingBoard board;
};
#endif