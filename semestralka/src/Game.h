#ifndef GAME
#define GAME
#include "PlayerLive.h"
#define ENDMIDDLE 18
class Game{
public:
    Game():player1("Player 1",30){};
    virtual void play() = 0; //A complex function to play a new game
    virtual void printAll() const = 0;
    virtual void initStart() = 0;
    virtual void finished() const = 0;
protected:
    void printEnd() const;
    static vector<string> END;
    PlayerLive player1;
    bool playerTurn = true; //1 for player1, 0 for player 2
    bool isDone = false;
};
#endif