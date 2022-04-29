#ifndef BOARD_H
#define BOARD_H
#include "CardPrintStorage.h"
#define MAXBOARDSIZE 5
using namespace std;
class PlayingBoard : public CardPrintStorage{
public:
    PlayingBoard():CardPrintStorage(MAXBOARDSIZE){};
    void getAttacked(shared_ptr<Card> attacker, int defender); //a Card from the opposing board attacks our defender at some index(indexing from 1)
    bool addToBoard(shared_ptr<Card> crd);
private:
};
#endif