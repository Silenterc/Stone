#include "BasicCard.h"
void BasicCard::print(unsigned int flag) const{
    switch(flag){
        case 1: cout << name;
                break;
        case 2: cout << "Basic Card";
                break;
        case 3: cout << damage;
                break;
        case 4: cout << health;
                break;
        default: break;
    }
}
shared_ptr<Card> BasicCard::clonePtr(){
    return make_shared<BasicCard>(*this);
}
void BasicCard::doBattlecry(Player& src, Player& trgt){}
void BasicCard::printOstream(ostream& out) const{
    out << name << ';' << "Basic Card" << ';' << damage << ';' << health << ';' << 0 << ';' << 0 << ';' << charged;
}