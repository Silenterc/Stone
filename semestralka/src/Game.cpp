#include "Game.h"
using namespace std;
vector<string> Game::END = {
{ "|-------     |\\      |     |---\\      " },
{ "|            | \\     |     |    \\    " },
{ "|            |  \\    |     |     \\   " },
{ "|-------     |   \\   |     |     |  " },
{ "|            |    \\  |     |     /  " },
{ "|            |     \\ |     |    /  " },
{ "|-------     |      \\|     |---/   " }
};
void Game::printEnd() const{
    for(const auto& row : END){
        printSpaces((getTermSize()/2) - ENDMIDDLE);
        for(const auto& col : row){
            cout << col;
        }
        cout << endl;
    } 
}
void Game::executeCommands(PlayerLive& src, Player& trgt){
    while(true){
        printAll();
        string in = src.getInput();
        if(in == "save"){
            saveGame();
            continue;
        } else if(in == "attack"){
            string from = src.getInput();
            int fr = stoi(from);
            if(fr <= 0 || fr > (src.boardSize())){
                cout << "Wrong from parameter" << endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                sleep(5);
                continue;
            }
            string trg = src.getInput();
            int to = stoi(trg);
            if(to > trgt.boardSize() || to < 0){
                cout << "Wrong target parameter" << endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                sleep(5);
                continue;
            }
            if(!(src.attack(fr, to, trgt))){
                cout << "Could not attack." << endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                sleep(5);
                continue;
            }
            if(src.isDead() || trgt.isDead()){
                return;
            }

        } else if (in == "play"){
            string ind = src.getInput();
            int index = stoi(ind);
            if(index <= 0 || index > src.handSize() || !src.isCharged() || !(src.playCard(index, trgt))){
                cout << "Could not play the requested card." << endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                sleep(5);
                continue;
            }
            src.uncharge();
            if(player1.isDead() || trgt.isDead()){
                return;
            }
        } else if (in == "end"){
            return;
        } else{
            cout << "Unknown command." << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            sleep(5);
        }  
    }
}