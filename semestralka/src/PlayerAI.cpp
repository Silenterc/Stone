#include "PlayerAI.h"
unique_ptr<Player> PlayerAI::clonePtr(){
    return make_unique<PlayerAI>(*this);
}
int PlayerAI::executeTurn(unique_ptr<Player>& trgt){
    
}