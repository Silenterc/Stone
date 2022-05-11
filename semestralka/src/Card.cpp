#include "Card.h"
#include "Player.h"
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
void BasicCard::doBattlecry(Player& src, Player& trgt){

}
void BasicCard::printOstream(ostream& out) const{
    out << name << ';' << "Basic Card" << ';' << damage << ';' << health << ';' << 0 << ';' << 0 << ';' << charged;
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
void TauntCard::doBattlecry(Player& src, Player& trgt){

}
void TauntCard::printOstream(ostream& out) const{
    out << name << ';' << "Taunt" << ';' << damage << ';' << health << ';' << 0 << ';' << 0 << ';' << charged;   
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
        case 5: effect -> printEffect(1); //Printing the first line of the battlecry description
                break;
        case 6: effect -> printEffect(2); //second line of the battlecry description
                break;
        default: break;
    }
}
shared_ptr<Card> BattlecryCard::clonePtr(){
    return make_shared<BattlecryCard>(*this);
}
void BattlecryCard::doBattlecry(Player& src, Player& trgt){
    effect -> doEffect(src, trgt);
}
void BattlecryCard::printOstream(ostream& out) const{
    out << name << ';' << "Battlecry" << ';' << damage << ';' << health << ';' << *effect << ';' << charged;
}
int BattlecryCard::getBattlecryLength(int row) const{
    return effect -> getLength(row);
}
void BattlecryCard::setEffect(string batID, int str){
    if(batID == "dce"){
        DrawCardEffect tmp(str);
        effect = tmp.copyPtr();
    } else if(batID == "bde"){
        BoardDamageEffect tmp(str);
        effect = tmp.copyPtr();
    } else if(batID == "ade"){
        AllDamageEffect tmp(str);
        effect = tmp.copyPtr();
    } else if(batID == "hbe"){
        HealBoardEffect tmp(str);
        effect = tmp.copyPtr();
    } else if(batID == "hhe"){
        HealHeroEffect tmp(str);
        effect = tmp.copyPtr();
    } else{
        throw invalid_argument("Wrong battlecry");
    }
}
