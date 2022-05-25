
#ifdef TESTING
#include "Menu.h"
#include <cassert>
using namespace std;
bool successfullyLoad(Menu& tMenu, Game& tGame, const string& path){
    bool gameType;
    assert(loadFile(path));
    ifstream in = loadFile(path);
    try{
        gameType = tMenu.extractGameType(in);
        tGame.loadGame(in, gameType);
    } catch(...){
        return false;
    }
    return true;
}
int main(){
    //Successfully setting an Effect
    BattlecryCard bat("n",4,5);
    bat.setEffect("dce", 1);
    bat.setEffect("ade", 1);
    bat.setEffect("hbe", 1);
    bat.setEffect("hhe", 1);
    bat.setEffect("bde", 1);
    //Loading files in wrong format
    Game g;
    Menu m;
    assert(!(successfullyLoad(m, g, "assets/saves/WrongFormat")));
    assert(!(successfullyLoad(m, g, "assets/saves/WrongFormat2")));
    assert(!(successfullyLoad(m, g, "assets/saves/WrongFormat3")));
    assert(!(successfullyLoad(m, g, "assets/saves/corrupt")));
    
    //Loading from config
    PlayerAI testAI;
    PlayerLive testLive;
    ifstream in = loadFile("assets/testConfig");
    testAI.loadInfo(in);
    testAI.loadDeck(in);
    testLive.loadInfo(in);
    testLive.loadDeck(in);
    assert(testAI.getHealth() == 30);
    assert(testLive.getHealth() == 30);
    //Drawing Cards over the limit
    for(int i = 0; i < MAXHANDSIZE; i++){
        assert((testAI.drawCard()).second);
        assert((testLive.drawCard()).second);
    }
    assert(testAI.deckSize() == 10);
    assert(testLive.deckSize() == 10);
    assert(!((testAI.drawCard()).second)); //It disposes of the Card not drawn
    assert(!((testLive.drawCard()).second));
    assert(testAI.deckSize() == 9); //10 - 1 = 9
    assert(testLive.deckSize() == 9);
    //Playing Cards on Board over the limit
    for(int i = 0; i < MAXBOARDSIZE; i++){
        testAI.charge();
        assert(testAI.playCard(1, testLive));
    }
    assert(testAI.boardSize() == MAXBOARDSIZE);
    assert(testAI.handSize() == 0);
    for(int i = 0; i < MAXBOARDSIZE; i++){
        testLive.charge();
        assert(testLive.playCard(1, testAI));
    }
    testAI.charge();
    testLive.charge();
    assert(testAI.boardSize() == MAXBOARDSIZE - 1);//Battlecry plazed from testLive should kill one
    assert(testLive.boardSize() == MAXBOARDSIZE);
    assert((testAI.drawCard()).second);
    assert((testLive.drawCard()).second);
    assert(testAI.playCard(1, testLive)); //Plays a Card which Draws a Card
    assert(testAI.handSize() == 1);
    testAI.charge();
    assert(!testAI.playCard(1, testLive));
    assert(testAI.handSize() == 1);
    assert(!testLive.playCard(1, testAI));
    assert(testAI.boardSize() == MAXBOARDSIZE);
    assert(testLive.boardSize() == MAXBOARDSIZE);
    assert(testLive.handSize() == 1);

}
#endif 