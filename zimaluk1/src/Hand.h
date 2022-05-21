#ifndef HAND_H
#define HAND_H
#include "CardPrintStorage.h"
#define MAXHANDSIZE 5
/**
 * @brief The Player's Hand which hold Cards ready to be played.
 * 
 */
class Hand : public CardPrintStorage{
public:
    Hand():CardPrintStorage(MAXHANDSIZE){};       
    /**
     * Tries to draw a Card from the Deck and add it to the Hand.
     * Discards the Card if the Hand is full.
     * @param deck 
     * @return pair<string, bool> Returns <name of card, false> if the Hand is full and this Card was discarded.
     */
    pair<string, bool> drawCard(Deck& deck); 
    /**
     * @brief To play the actual card and remove it from hand.
     * 
     * @param cardNO Index of the Card to play(indexing from 1).
     * @return shared_ptr<Card> Played Card
     */
    shared_ptr<Card> playCard(int cardNO);
protected:
    
    
};

#endif