#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#define MAXHANDSIZE 5
class Hand{
public:
    Hand():size(0){};               
    pair<string, bool> drawCard(Deck& deck); //Returns false,name of the card and discards the card if the hand is full, otherwise adds to cards
    shared_ptr<Card> getCard(int cardNO) const; //To see which card the player has chosen to play, but not actually play it(indexing from 1) 
    shared_ptr<Card> playCard(int cardNO);//To play the actual card(remove it from hand.)
    void print() const;
    size_t getSize(){
        return size;
    }
private:
vector< shared_ptr<Card> > cards;
size_t size;
int prevPrinted(unsigned int row, size_t column, int prevDiff) const;
void printSpaces(int spaces) const;
};

#endif