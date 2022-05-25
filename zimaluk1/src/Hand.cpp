#include "Hand.h"
pair<string, bool> Hand::drawCard(Deck& deck){
    if(isFull()){
        return(make_pair<string,bool>(deck.drawCard() -> getName(), false));
    }
    if(deck.isEmpty()){
        return(make_pair<string,bool>("", false));
    }
    shared_ptr<Card> newOne = deck.drawCard();
    pair<string,bool> toBeRet = make_pair<string,bool>(newOne -> getName(), true);
    cards.push_back(newOne);
    size++;
    return toBeRet;
}
shared_ptr<Card> Hand::playCard(int cardNO){
    shared_ptr<Card> toBeRet = cards[cardNO - 1];
    cards.erase(cards.begin() + (cardNO - 1));
    size--;
    return toBeRet;
}
