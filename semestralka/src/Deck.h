#pragma once
#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
using namespace std;
class Deck{
public:
    Deck():size(0){};
    Deck& operator =(const Deck& second);
    shared_ptr<Card> drawCard();
    void shuffle();
    void addCard(shared_ptr<Card>);
    void loadCards();
    size_t getSize() const{
        return size;
    }
private:
    vector< shared_ptr<Card> > cards;
    size_t size;
};
#endif