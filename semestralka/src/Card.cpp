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
void TauntCard::printCard(unsigned int flag, int spaces) const{
    cout << "tauntcard" << endl;
}
void BattlecryCard::printCard(unsigned int flag, int spaces) const{
    cout << "batlecrycard" << endl;
}
