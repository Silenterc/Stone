#ifndef CPS_H
#define CPS_H
#include "Deck.h"
#include "helperFunc.h"
#include <queue>
/**
 * Parent Class for Hand and Board.
 * Holds Cards and prints them in the correct format. 
 * 
 */
class CardPrintStorage{
public:
    CardPrintStorage(size_t max):size(0), maxStorageSize(max){};
    /**
     * @brief Performs a deep copy of the CardPrintStorage Object.
     */
    CardPrintStorage(const CardPrintStorage& src);
    /**
     * @brief Creates a deep copy of the assigned CardPrintStorage Object.
     */
    CardPrintStorage& operator =(const CardPrintStorage& src);
    /**
     * @brief To view a Card at a certain index (indexing from 1)
     * 
     * @param cardNO index of the Card(indexing from 1)
     * @return shared_ptr<Card> The viewed Card
     */
    shared_ptr<Card> viewCard(unsigned long cardNO) const; 
    /**
     * @brief Prints the Storage
     * The print function is interactive with Terminal size. 
     * It prints the Cards next to each other with a calculated amount of spaces,
     * so that the Cards are always aligned.
     * 
     */
    void print() const;
    /**
     * Prints the Cards as 5x4 objects made out of stars
     * 
     */
    void printCensored() const;
    size_t getSize() const{
        return size;
    }
    /**
     * @brief Returns the value of the Board
     * 
     * @return int Sum of all Cards' values
     */
    int getValue() const;
    void removeCard(int cardNO){
        cards.erase(cards.begin() + (cardNO - 1));
        size--;
    }
    bool isFull() const;
    bool isEmpty() const{
        return (size <= 0);
    }
    /**
     * Writes the size of the Board and then each Card on it into out. 
     * 
     */
    friend ostream& operator <<(ostream& out, const CardPrintStorage& s){
        s.printOstream(out);
        return out;
    }
    /**
     * Loads and creates all the Cards specified in the ifstream.
     * Throws an exception is there was a problem
     * 
     */
    void load(ifstream& in);
    vector< shared_ptr<Card>> getCards() const{
        return cards;
    }
protected:
    /**
     * @brief Hold all the Cards that this Storage has.
     * 
     */
    vector< shared_ptr<Card>> cards;
    size_t size;
    size_t maxStorageSize;
    /**
     * @brief 
     * This function will calculate the difference between the previous words printed, 
     * so I can then balance out the amount of spaces to print for each attribute.
     * The first card printed actually has a set amount of spaces(SPACECONSTANT)
     * @param row Which row of info of a Card I want to print on this line
     * @param column Which column = index of the Card am I printing
     * @param prevDiff Previous difference in the previous words printed
     * @return int 
     */
    int prevPrinted(unsigned int row, size_t column, int prevDiff) const;
    void printOstream(ostream& out) const;
};
#endif