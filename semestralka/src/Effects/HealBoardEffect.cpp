#include "HealBoardEffect.h"
#include "../Player.h"
HealBoardEffect::HealBoardEffect(int s):Effect(s){
    string desc("Add ");
    desc.append(to_string(strength));
    desc.append(" health to");
    effectDesc.push_front(desc);
    desc = "your board";
    effectDesc.push_back(desc);
}
void HealBoardEffect::doEffect(Player& src, Player& trgt){
    src.getBoard().getDamagedOrHealed(strength);
}
void HealBoardEffect::printOstream(ostream& out) const{
    out << "hbe;" << strength;
}
void HealBoardEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int HealBoardEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
    }
}
unique_ptr<Effect> HealBoardEffect::copyPtr(){
    return make_unique<HealBoardEffect> (*this);
}