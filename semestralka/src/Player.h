#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Hand.h"
#include "Deck.h"
using namespace std;
class Player : public Entity{
public:
    Player(const string& nm,int hlth):Entity(nm,hlth){};
    pair<string, bool> drawCard();
    void setDeck(Deck& d){
        deck = d;
    }
protected:
    Deck deck;
    Hand hand;
};
#endif