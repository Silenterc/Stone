#include "Card.h"
#include <iostream>
bool Card::attack(Entity& second){
    second.health -= damage;
    health -= second.damage;
    return true;
}
void BasicCard::printCard(unsigned int flag, int spaces) const{
    cout << "basiccard" << endl;
}
shared_ptr<Card> BasicCard::clonePtr(){
    return make_shared<BasicCard>(*this);
}
void TauntCard::printCard(unsigned int flag, int spaces) const{
    cout << "tauntcard" << endl;
}
shared_ptr<Card> TauntCard::clonePtr(){
    return make_shared<TauntCard>(*this);
}
void BattlecryCard::printCard(unsigned int flag, int spaces) const{
    cout << "batlecrycard" << endl;
}
shared_ptr<Card> BattlecryCard::clonePtr(){
    return make_shared<BattlecryCard>(*this);
}
