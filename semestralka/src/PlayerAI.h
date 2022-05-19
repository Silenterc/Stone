#ifndef AI
#define AI
#include "Player.h"
#include <algorithm>
#include <climits>
using namespace std;
class PlayerAI : public Player{
public:
    PlayerAI(const string& nm,int hlth) : Player(nm, hlth){};
    PlayerAI() = default;
    unique_ptr<Player> clonePtr() override;
    int executeTurn(unique_ptr<Player>& trgt) override;
    void printConfirmation() const override{};
protected:
    void clearBoard(unique_ptr<Player>& trgt);
    void tryPreventLethal(unique_ptr<Player>& trgt);
    void getLethalRec(PlayerAI& ai, unique_ptr<Player>& trgt);
    bool hasLethal(const PlayerAI& ai,unique_ptr<Player>& trgt) const;
    bool attackOne(PlayerAI& src, unique_ptr<Player>& trgt, PlayingBoard& enemyB, unsigned long index);
    void playTurn(unique_ptr<Player>& trgt);
    int evalOne(shared_ptr<Card> enemyCard, PlayingBoard& friendlyBoard);
};
#endif