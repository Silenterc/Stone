#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Deck.h"
#include "Hand.h"

using namespace std;
class Player : public Entity{
public:
    Player(const string& nm,int hlth):Entity(nm,hlth){};

protected:
    Deck d;
};
#endif