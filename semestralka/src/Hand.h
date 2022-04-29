#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include "Deck.h"
#include "CardPrintStorage.h"
#include <vector>
#define MAXHANDSIZE 5
class Hand : public CardPrintStorage{
public:
    Hand():CardPrintStorage(MAXHANDSIZE){};               
    pair<string, bool> drawCard(Deck& deck); //Returns false,name of the card and discards the card if the hand is full, otherwise adds to cards
    shared_ptr<Card> playCard(int cardNO);//To play the actual card(remove it from hand.)
private:
    
};

#endif