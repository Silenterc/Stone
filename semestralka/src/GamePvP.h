#ifndef PVP
#define PVP
#include "Game.h"
class GamePvP : public Game{
public:
    GamePvP():Game(),player2("Player 2", 30){};
    void play() override;
    void printAll() const override;
    void initStart() override;
    void finished() const override;
    void saveGame() const override;
    void loadGame(ifstream& in) override;
protected:
    PlayerLive player2;
    void playLoaded() override;
};
#endif