#pragma once
#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
using namespace std;
class Deck{
public:
    Deck(){};
    Deck(const string& fileName);
    shared_ptr<Card> drawCard();
    void shuffle();
    void addCard(shared_ptr<Card>);
private:
    vector< shared_ptr<Card> > cards;
};
#endif