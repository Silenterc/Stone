#include "DrawCardEffect.h"
#include "../Player.h"
DrawCardEffect::DrawCardEffect(int s):Effect(s){
    string desc("Draw ");
    if(strength == 1){
        desc.append("a card");    
    } else{
        desc.append(to_string(strength));
        desc.append(" cards");
    }
    effectDesc.push_front(desc);

}
void DrawCardEffect::doEffect(Player& src, Player& trgt){
    src.drawCard();
}
void DrawCardEffect::printOstream(ostream& out) const{
    out << "dce;" << strength;
}
void DrawCardEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int DrawCardEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
    }
}
shared_ptr<Effect> DrawCardEffect::copyPtr(){
    return make_shared<DrawCardEffect> (*this);
}