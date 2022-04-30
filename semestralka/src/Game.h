#include "PlayerLive.h"
class Game{
public:
    Game():player1("Player 1",30){};
    virtual void play() = 0; //A complex function to play a new game
    virtual void printAll() = 0;

protected:
    PlayerLive player1;
    bool playerTurn;
    bool isDone = false;
};