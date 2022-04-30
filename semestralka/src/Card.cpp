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
list<string> battlecryIDtoString(int ID){
    switch(ID){
        case 1: return list<string>{"Draw a card and add","1 health to your hero"};
        case 2: return list<string>{"Deal 2 damage to","the enemy board"};
        case 3: return list<string>{"Deal 3 damage to","everybody"};
        case 4: return list<string>{"Add 2 health to","your board and hero"};
        case 5: return list<string>{"Deal 2 damage to","the enemy hero"};
        default: throw invalid_argument("INVALID BATTLECRYID");
    }
}
int BattlecryCard::getBattlecryLength(int batNO, int row) const{
    if(row == 1){
        return (int)battlecryIDtoString(batNO).front().length();
     }else{
        return (int)battlecryIDtoString(batNO).back().length();
     }
}
