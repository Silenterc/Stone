#ifndef PLAYERLIVE
#define PLAYERLIVE
#include "Player.h"
using namespace std;
class PlayerLive : public Player{
public:
    PlayerLive(const string& nm,int hlth) : Player(nm, hlth){};
    stringstream getInput();
protected:
};
#endif