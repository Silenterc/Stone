#include "BoardDamageEffect.h"
#include "../Player.h"
BoardDamageEffect::BoardDamageEffect(int s):Effect(s){
    string desc("Deal ");
    desc.append(to_string(strength));
    desc.append(" damage to");
    effectDesc.push_front(desc);
    desc = "the enemy board";
    effectDesc.push_back(desc);
}
void BoardDamageEffect::doEffect(Player& src, Player& trgt){
    trgt.getBoard().getDamagedOrHealed(-strength);
}
void BoardDamageEffect::printOstream(ostream& out) const{
    out << "bde;" << strength;
}
void BoardDamageEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int BoardDamageEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
    }
}
shared_ptr<Effect> BoardDamageEffect::copyPtr(){
    return make_shared<BoardDamageEffect> (*this);
}