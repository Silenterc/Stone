#ifndef PLAYERLIVE
#define PLAYERLIVE
#include "Player.h"
using namespace std;
class PlayerLive : public Player{
public:
    PlayerLive(const string& nm,int hlth) : Player(nm, hlth){};
    PlayerLive() = default;
    string getInput() const;
    unique_ptr<Player> clonePtr() override;
    int executeTurn(unique_ptr<Player>& trgt) override;
    void printConfirmation() const override;
    void print(unsigned int flag) const override;
protected:
    
};
#endif