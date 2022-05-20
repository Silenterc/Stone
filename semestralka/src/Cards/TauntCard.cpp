#include "TauntCard.h"
void TauntCard::print(unsigned int flag) const{
    switch(flag){
        case 1: cout << name;
                break;
        case 2: cout << "Taunt";
                break;
        case 3: cout << damage;
                break;
        case 4: cout << health;
                break;
        default: break;
    }
}
shared_ptr<Card> TauntCard::clonePtr(){
    return make_shared<TauntCard>(*this);
}
void TauntCard::doBattlecry(Player& src, Player& trgt){

}
void TauntCard::printOstream(ostream& out) const{
    out << name << ';' << "Taunt" << ';' << damage << ';' << health << ';' << 0 << ';' << 0 << ';' << charged;   
}