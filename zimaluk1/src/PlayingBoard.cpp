#include "PlayingBoard.h"
void PlayingBoard::getAttacked(shared_ptr<Card> attacker, int defender){
    attacker -> attack(*(cards[defender - 1]));
    if(cards[defender - 1] -> isDead()){
        cards.erase(cards.begin() + (defender - 1));
        size--;
    }
}
bool PlayingBoard::addToBoard(shared_ptr<Card> crd){
    if(size >= MAXBOARDSIZE){
        return false;
    }
    cards.push_back(crd);
    size++;
    return true;
}
bool PlayingBoard::hasTaunt() const{
    for(const auto& c : cards){
        if(c -> isTaunt()){
            return true;
        }
    }
    return false;
}
void PlayingBoard::chargeB(){
    for(auto& c : cards){ 
        c -> charge();
    }
}
void PlayingBoard::getDamagedOrHealed(int change){
    for(unsigned long i = 0; i < size;){
        cards[i] -> changeHealth(change);
        if(cards[i] -> isDead()){
            cards.erase(cards.begin() + i);
            size--;
        } else{
            i++;
        }
    }
}
bool PlayingBoard::isUncharged() const{
    for(const auto& c : cards){
        if(c -> isCharged()){
            return false;
        }
    }
    return true;
}
unsigned long PlayingBoard::getPriorityIndex() const{
    unsigned long highestValueIndex = 1;
    unsigned long highestValue = 0, currValue = 0;
    for(unsigned long i = 0; i < size; i++){
        if(cards[i] -> isTaunt()){
            return (i + 1);
        }
        currValue = cards[i] -> getValue();
        if(currValue > highestValue){
            highestValue = currValue;
            highestValueIndex = i + 1;
        }
    }
    return highestValueIndex;
}
void PlayingBoard::evalDead(){
    for(size_t i = 0; i < size;){
        if(cards[i] -> isDead()){
            removeCard(i + 1);
        } else{
            i++;
        }
    }
}
