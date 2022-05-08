#ifndef PVP
#define PVP
#include "Game.h"
class GamePvP : public Game{
public:
    GamePvP():Game(),player2("Player 2", 30){};
    void play() override;
    void printAll() const override;
    void initStart() override;
    void executeCommands(PlayerLive& src, PlayerLive& trgt);
    void finished() const override;
protected:
    PlayerLive player2;

};
#endif