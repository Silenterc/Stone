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