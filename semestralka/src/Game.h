#ifndef GAME
#define GAME
#include "PlayerLive.h"
#include "PlayerAI.h"
#define ENDMIDDLE 18
class Game{
public:
    Game(){};
    void play() ; //A complex function to play a new game
    void printAll() const;
    void initStartPvP();
    void initStartAI();
    void finished() const;
    void saveGame() const;
    void loadGame(ifstream& in, bool isPvP);
    
protected:
    void printEnd() const;
    void playLoaded();
    static vector<string> END;
    unique_ptr<Player> player1;
    unique_ptr<Player> player2;
    bool playerTurn = true; //1 for player1, 0 for player 2
    bool isDone = false;
    bool isFirstRound = true;
};
#endif