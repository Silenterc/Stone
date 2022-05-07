#ifndef GAME
#define GAME
#include "PlayerLive.h"
class Game{
public:
    Game():player1("Player 1",30){};
    virtual void play() = 0; //A complex function to play a new game
    virtual void printAll() = 0;
    virtual void initStart() = 0;

protected:
    PlayerLive player1;
    bool playerTurn; //1 for player1, 0 for player 2
    bool isDone = false;
};
#endif