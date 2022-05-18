#ifndef AI
#define AI
#include "Player.h"
using namespace std;
class PlayerAI : public Player{
public:
    PlayerAI(const string& nm,int hlth) : Player(nm, hlth){};
    unique_ptr<Player> clonePtr() override;
    int executeTurn(unique_ptr<Player>& trgt) override;
    void printConfirmation() const override{};
protected:
    void tryGetLethal(unique_ptr<Player>& trgt);
    void tryPreventLethal(unique_ptr<Player>& trgt);
};
#endif