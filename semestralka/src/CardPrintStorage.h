#ifndef CPS_H
#define CPS_H
#include "Card.h"
#include "Deck.h"
#include <vector>
class CardPrintStorage{
public:
    CardPrintStorage(int max):size(0), maxStorageSize(max){};
    shared_ptr<Card> viewCard(int cardNO) const; //To see which card the player has chosen to play, but not actually play it(indexing from 1) 
    void print() const;
    size_t getSize(){
        return size;
    }
protected:
    vector< shared_ptr<Card> > cards;
    size_t size;
    int maxStorageSize;
    int prevPrinted(unsigned int row, size_t column, int prevDiff) const;
    void printSpaces(int spaces) const;
};
#endif