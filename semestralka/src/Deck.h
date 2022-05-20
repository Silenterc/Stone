
#ifndef DECK_H
#define DECK_H
#include "Cards/Card.h"
#include "Cards/BasicCard.h"
#include "Cards/BattlecryCard.h"
#include "Cards/TauntCard.h"
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
class Deck{
public:
    Deck():size(0){};
    Deck& operator =(const Deck& second);
    shared_ptr<Card> drawCard();
    void shuffle();
    void addCard(shared_ptr<Card>);
    void loadCards(ifstream& in);
    size_t getSize() const{
        return size;
    }
    bool isEmpty() const{
        return size == 0 ? true : false ;
    }
    friend ostream& operator <<(ostream& out, const Deck& d){
        d.printOstream(out);
        return out;
    }
private:
    void printOstream(ostream& out) const;
    vector< shared_ptr<Card> > cards;
    size_t size;
};
#endif