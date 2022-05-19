#ifndef CPS_H
#define CPS_H
#include "Deck.h"
class CardPrintStorage{
public:
    CardPrintStorage(int max):size(0), maxStorageSize(max){};
    CardPrintStorage(const CardPrintStorage& src);
    CardPrintStorage& operator =(const CardPrintStorage& src);
    shared_ptr<Card> viewCard(unsigned long cardNO) const; //To see which card the player has chosen to play, but not actually play it(indexing from 1) 
    void print() const;
    void printCensored() const;
    size_t getSize() const{
        return size;
    }
    int getValue() const;
    void removeCard(int cardNO){
        cards.erase(cards.begin() + (cardNO - 1));
        size--;

    }
    virtual bool isFull() const = 0;
    friend ostream& operator <<(ostream& out, const CardPrintStorage& s){
        s.printOstream(out);
        return out;
    }
    void load(ifstream& in);
    vector< shared_ptr<Card> > getCards() const{
        return cards;
    }
    void sort();
    bool nextPerm();
protected:
    vector< shared_ptr<Card> > cards;
    size_t size;
    int maxStorageSize;
    int prevPrinted(unsigned int row, size_t column, int prevDiff) const;
    void printStars(int stars) const;
    void printOstream(ostream& out) const;
};
#endif