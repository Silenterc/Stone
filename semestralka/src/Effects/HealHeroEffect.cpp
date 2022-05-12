#include "HealHeroEffect.h"
#include "../Player.h"
HealHeroEffect::HealHeroEffect(int s):Effect(s){
    string desc("Add ");
    desc.append(to_string(strength));
    desc.append(" health to");
    effectDesc.push_front(desc);
    desc = "your hero";
    effectDesc.push_back(desc);
}
void HealHeroEffect::doEffect(Player& src, Player& trgt){
    src.changeHealth(strength);
}
void HealHeroEffect::printOstream(ostream& out) const{
    out << "hhe;" << strength;
}
void HealHeroEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int HealHeroEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
    }
}
shared_ptr<Effect> HealHeroEffect::copyPtr(){
    return make_shared<HealHeroEffect> (*this);
}