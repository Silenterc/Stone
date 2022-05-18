#include "PlayerAI.h"
unique_ptr<Player> PlayerAI::clonePtr(){
    return make_unique<PlayerAI>(*this);
}
int PlayerAI::executeTurn(unique_ptr<Player>& trgt){
    tryGetLethal(trgt);
    //tryPreventLethal(trgt);
    return 0;
}
void PlayerAI::tryGetLethal(unique_ptr<Player>& trgt){
    unique_ptr<Player> enemy = trgt -> clonePtr();
    PlayerAI ai = *this;
    ai. dealDmgOrHealBoard(- 50);
    print(1);
    ai. print(1);
    *this = ai;
    print(1);
}