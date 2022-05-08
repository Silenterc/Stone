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