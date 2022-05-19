#include "PlayerAI.h"
unique_ptr<Player> PlayerAI::clonePtr(){
    return make_unique<PlayerAI>(*this);
}
int PlayerAI::executeTurn(unique_ptr<Player>& trgt){
    //getLethalRec(*this, trgt);
    tryGetLethal(trgt);
    //tryPreventLethal(trgt);
    return 0;
}
void PlayerAI::tryGetLethal(unique_ptr<Player>& trgt){
    bool hasBasicAttacked = false; //I only need to call attackRec once for all the cards that are not Battlecry(the outcome would always be the same)
    for(size_t i = 1; i <= handSize(); i++){ //First We play a Card and then attack
        PlayerAI ai = *this;
        unique_ptr<Player> enemy = trgt -> clonePtr();
        if(ai.hand.viewCard(i) -> isBattlecry()){
            ai.playCard(i, *enemy);
            attackRec(ai, enemy);
        } else{
            ai.playCard(i, *enemy);
            if(!hasBasicAttacked){
                hasBasicAttacked = true;
                attackRec(ai, enemy);
            } 
        }
    }
}
void PlayerAI::attackRec(PlayerAI& src, unique_ptr<Player>& trgt){
    for(size_t fr = 1; fr <= src.boardSize(); fr++){
        if(!(src.board.viewCard(fr) -> isCharged())){
            continue;
        }
        PlayerAI ai = src;
        unique_ptr<Player> enemy = trgt -> clonePtr();
        for(size_t to = 0; to <= enemy -> boardSize(); to++){
            PlayerAI ai2 = ai;
            unique_ptr<Player> enemy2 = enemy -> clonePtr();
            ai2.attack(fr, to, *enemy2);
            enemy2 -> print(0);
            ai2.print(1);
            attackRec(ai2, enemy2);
        }
    }
}
void PlayerAI::getLethalRec(PlayerAI& src, unique_ptr<Player>& trgt){
    //src.print(1);
    cout << src.isCharged() <<", "<<src.board.isUncharged() << endl;
    if((src.board.isUncharged()|| src.isDead() || trgt -> isDead())){
        cout <<"Finished" << endl;
        trgt -> print(0);
        src.print(1);
        return;
    }
    unique_ptr<Player> enemy = trgt -> clonePtr();
    PlayerAI ai = src;
    for(size_t i = 0; i <= ai.hand.getSize(); i++){
        //cout <<"cardPlayed: " << i << endl;
        unique_ptr<Player> enemy = trgt -> clonePtr();
        PlayerAI ai1 = ai;
        if(i != 0 && ai1.isCharged()){
            ai1.playCard(i, *enemy);
        }
        for(size_t fr = 1; fr <= ai1.board.getSize(); fr++){
            unique_ptr<Player> enemy2 = enemy -> clonePtr();
            PlayerAI ai2 = ai1;
            for(size_t t = 0; t <= enemy2 -> getBoard().getSize(); t++){
                unique_ptr<Player> enemy3 = enemy2 -> clonePtr();
                PlayerAI ai3 = ai2;   
                ai3.attack(fr, t, *enemy3);
                cout <<"getlethal" << endl;
                getLethalRec(ai3, enemy3);
            }
        }
    }

}
bool PlayerAI::hasLethal(const PlayerAI& ai, unique_ptr<Player>& trgt) const{
    if(ai.board.combinedDamage() >= trgt -> getHealth() && !(trgt -> hasTauntOnBoard())){
        return true;
    }
    return false;
}