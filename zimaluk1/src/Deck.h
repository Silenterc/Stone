
#ifndef DECK_H
#define DECK_H
#include "Cards/Card.h"
#include "Cards/BasicCard.h"
#include "Cards/BattlecryCard.h"
#include "Cards/TauntCard.h"
#include <vector>
#include <algorithm>
#include <random>
/**
 * @brief Deck which stores Cards.
 * 
 */
class Deck{
public:
    Deck():size(0){};
    /**
     * @brief Performs a deep copy of the assigned Deck.
     * 
     */
    Deck& operator =(const Deck& second);
    /**
     * @brief Removes a Card from it's Vector and returns it
     * 
     * @return shared_ptr<Card> The drawn Card
     */
    shared_ptr<Card> drawCard();
    /**
     * @brief Shuffles the vector of Cards
     * 
     */
    void shuffle();
    /**
     * @brief Adds a Card to the Vector
     * 
     */
    void addCard(shared_ptr<Card>);
    /**
     * Loads, creates and puts the Cards in the Deck from the ifstream.
     * Throws an exception if something is not right.
     * 
     * @param in 
     */
    void loadCards(ifstream& in);
    size_t getSize() const{
        return size;
    }
    bool isEmpty() const{
        return size == 0 ? true : false ;
    }
    /**
     * @brief Writes the size of the Deck and then each Card on it into out. 
     * 
     */
    friend ostream& operator <<(ostream& out, const Deck& d){
        d.printOstream(out);
        return out;
    }
private:
    void printOstream(ostream& out) const;
    /**
     * @brief Holds all the Cards that this Deck has.
     * 
     */
    vector< shared_ptr<Card> > cards;
    size_t size;
};
#endif