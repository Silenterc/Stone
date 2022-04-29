#include "Card.h"
#include <iostream>
bool Card::attack(Entity& second){
    second.health -= damage;
    health -= second.damage;
    return true;
}
size_t Card::getDamageLength() const{
    return (to_string(damage)).length();
}
size_t Card::getHealthLength() const{
    return (to_string(health)).length();
}
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
void BattlecryCard::print(unsigned int flag) const{
    switch(flag){
    case 1: cout << name;
            break;
    case 2: cout << "Battlecry";
            break;
    case 3: cout << damage;
            break;
    case 4: cout << health;
            break;
    default: break;
    }
}
shared_ptr<Card> BattlecryCard::clonePtr(){
    return make_shared<BattlecryCard>(*this);
}
