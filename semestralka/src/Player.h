#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Hand.h"
#include "Deck.h"
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
    shared_ptr<Card> playCard(int NO){
        return hand.playCard(NO);
    }
protected:
    Deck deck;
    Hand hand;
};
#endif