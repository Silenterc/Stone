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
bool PlayingBoard::isFull() const{
    if(size >= MAXBOARDSIZE){
        return true;
    }
    return false;
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
int PlayingBoard::combinedDamage() const{
    int sum = 0;
    for(const auto& c : cards){
        if(c -> isCharged()){
            sum += c -> getDamage();
        }
    }
    return sum;
}
bool PlayingBoard::isUncharged() const{
    for(const auto& c : cards){
        if(c -> isCharged()){
            return false;
        }
    }
    return true;
}
