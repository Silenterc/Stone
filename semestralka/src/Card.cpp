#include "Card.h"
#include <iostream>
bool Card::attack(Entity& second){
    second.health -= damage;
    health -= second.damage;
    uncharge();
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
void BasicCard::printOstream(ostream& out) const{
    out << name << ';' << "Basic Card" << ';' << damage << ';' << health << ';' << 0 << ';' << charged;
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
void TauntCard::printOstream(ostream& out) const{
    out << name << ';' << "Taunt" << ';' << damage << ';' << health << ';' << 0 << ';' << charged;   
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
        case 5: cout << battlecryIDtoString(battlecryID).front(); //Printing the first line of the battlecry description
                break;
        case 6: cout << battlecryIDtoString(battlecryID).back(); //second line of the battlecry description
                break;
        default: break;
    }
}
shared_ptr<Card> BattlecryCard::clonePtr(){
    return make_shared<BattlecryCard>(*this);
}
void BattlecryCard::printOstream(ostream& out) const{
    out << name << ';' << "Battlecry" << ';' << damage << ';' << health << ';' << battlecryID << ';' << charged;
}
int BattlecryCard::getBattlecryLength(int batNO, int row) const{
    if(row == 1){
        return (int)battlecryIDtoString(batNO).front().length();
     }else{
        return (int)battlecryIDtoString(batNO).back().length();
     }
}
