#ifndef BOARD_H
#define BOARD_H
#include "CardPrintStorage.h"
#define MAXBOARDSIZE 5
using namespace std;
class PlayingBoard : public CardPrintStorage{
public:
    PlayingBoard():CardPrintStorage(MAXBOARDSIZE){};
    void getAttacked(shared_ptr<Card> attacker, int defender); //a Card from the opposing board attacks our defender at some index(indexing from 1)
    bool addToBoard(shared_ptr<Card> crd);                     //both take damage, our defender gets erased if he dies
    bool hasTaunt() const;
    void chargeB(); //set charged status to true for all the cards on the board, so they can attack
    void getDamagedOrHealed(int change); //change > 0 = heal, change < 0 = damage
    int combinedDamage() const;
    bool isUncharged() const;
    unsigned long getPriorityIndex() const;
    void evalDead();
private:
};
#endif