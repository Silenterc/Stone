#ifndef AI
#define AI
#include "Player.h"
using namespace std;
class PlayerAI : public Player{
public:
    PlayerAI(const string& nm,int hlth) : Player(nm, hlth){};
    PlayerAI() = default;
    unique_ptr<Player> clonePtr() override;
    int executeTurn(unique_ptr<Player>& trgt) override;
    void printConfirmation() const override{};
    void print(unsigned int flag) const override;
protected:
    void clearBoard(unique_ptr<Player>& trgt);
    bool attackOne(PlayerAI& src, unique_ptr<Player>& trgt, PlayingBoard& enemyB, unsigned long index);
    int evalOne(shared_ptr<Card> enemyCard, PlayingBoard& friendlyBoard);
    void performAttacking(PlayerAI& src, unique_ptr<Player>& trgt);
    void printTurn(PlayerAI& src, unique_ptr<Player>& trgt) const;
};
#endif