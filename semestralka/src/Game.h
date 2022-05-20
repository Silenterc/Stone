#ifndef GAME
#define GAME
#include "PlayerLive.h"
#include "PlayerAI.h"
#define ENDMIDDLE 18
#define FIRSTTURNDRAW 3
class Game{
public:
    Game(){};
    void play(bool justLoaded = false) ; //A complex function to play a new game
    void printAll() const;
    void initStart(bool PvP);
    void finished() const;
    void saveGame() const;
    void loadGame(ifstream& in, bool PvP);
    
protected:
    void printEnd() const;
    void playLoaded();
    void drawsCard(bool plr);
    void changePlayerTurn();
    void initPlayers();
    unique_ptr<Player>& getPlayer(bool plr);
    static vector<string> END;
    unique_ptr<Player> player1;
    unique_ptr<Player> player2;
    bool playerTurn = true; //1 for player1, 0 for player 2
    bool isDone = false;
    int isFirstRound = 2;
    bool isPvP;
};
#endif