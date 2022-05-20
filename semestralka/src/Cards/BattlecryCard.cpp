#include "BattlecryCard.h"
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