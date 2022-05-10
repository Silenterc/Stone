#ifndef GAMEAI
#define GAMEAI
#include "Game.h"
#include "PlayerAI.h"
using namespace std;
class GameAI : public Game{
    GameAI():Game(),player2("Player 2", 30){};
    void play() override;
    void printAll() const override;
    void initStart() override;
    void finished() const override;
    void saveGame() const override;
    void loadGame(ifstream& in) override;
protected:
    PlayerAI player2;
    void playLoaded() override;
};
#endif