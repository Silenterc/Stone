#include "AllDamageEffect.h"
#include "../Player.h"
AllDamageEffect::AllDamageEffect(int s):Effect(s){
    string desc("Deal ");
    desc.append(to_string(strength));
    desc.append(" damage to");
    effectDesc.push_front(desc);
    desc = "everybody";
    effectDesc.push_back(desc);
}
void AllDamageEffect::doEffect(Player& src, Player& trgt){
    src.getBoard().getDamagedOrHealed(-strength);
    trgt.getBoard().getDamagedOrHealed(-strength);
    src.changeHealth(-strength);
    trgt.changeHealth(-strength);
}
void AllDamageEffect::printOstream(ostream& out) const{
    out << "ade;" << strength;
}
void AllDamageEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int AllDamageEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
    }
}
shared_ptr<Effect> AllDamageEffect::copyPtr(){
    return make_shared<AllDamageEffect> (*this);
}