#ifndef BOARD_H
#define BOARD_H
#include "CardPrintStorage.h"
#define MAXBOARDSIZE 5
using namespace std;
/**
 * @brief A Board which holds Cards which can attack and be attacked by the Cards on the enemy Board.
 * 
 */
class PlayingBoard : public CardPrintStorage{
public:
    PlayingBoard():CardPrintStorage(MAXBOARDSIZE){};
    /**
     * @brief A Card from this Board gets attacked by an enemy Card.
     * a Card from the opposing board attacks our defender at some index(indexing from 1)
     * both take damage, our defender gets erased if he dies
     * @param attacker enemy  
     * @param defender index of the defender
     */
    void getAttacked(shared_ptr<Card> attacker, int defender); 
    /**
     * @brief Adds a card to the Board(the vector of Card pointers)
     * 
     * @param crd Card to be added
     * @return true Succesfully added
     * @return false The Board was full 
     */
    bool addToBoard(shared_ptr<Card> crd);   
    /**
     * @brief Checks if there is a Taunt on this Board
     * 
     * @return true There is
     * @return false There is not
     */
    bool hasTaunt() const;
    /**
     * @brief Set charged status to true for all the cards on the board, so they can attack
     * 
     */
    void chargeB(); 
    /**
     * @brief Change the health of all the Cards on this Board
     * change > 0 = heal, change < 0 = damage
     */
    void getDamagedOrHealed(int change);
    /**
     * @brief Check if every Card cannot attack(is uncharged)
     * 
     * @return true Every Card is not charged
     * @return false There is a card that is charged
     */
    bool isUncharged() const;
    /**
     * @brief Returns an index of a Card with the highest priority/value
     * If there is a Taunt, it has highest priority. If there is not, then
     * the Card with the highest value is chosen.
     * @return unsigned long Index of the Card with the highest priority (indexing from 1) 
     */
    unsigned long getPriorityIndex() const;
    /**
     * @brief Iterate through the board and remove Cards which are dead.
     * 
     */
    void evalDead();
private:
};
#endif