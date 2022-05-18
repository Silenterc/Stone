#ifndef PLAYERLIVE
#define PLAYERLIVE
#include "Player.h"
using namespace std;
class PlayerLive : public Player{
public:
    PlayerLive(const string& nm,int hlth) : Player(nm, hlth){};
    string getInput() const;
    unique_ptr<Player> clonePtr() override;
    int executeTurn(unique_ptr<Player>& trgt) override;
    void printConfirmation() const override;
protected:
    
};
#endif