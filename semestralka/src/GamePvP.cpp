#include "GamePvP.h"
using namespace std;
void GamePvP::play(){
    initStart();
    while(!isDone){
        printAll();
        if(playerTurn){
            executeCommands(player1, player2);
            playerTurn = false;
            player2.chargeBoard();
        
        } else{
            executeCommands(player2, player1);
            playerTurn = true;
            player1.chargeBoard();
        
        }
    }
}
void GamePvP::printAll(){
    cout << "\033[H\033[2J" << flush;
    if(playerTurn){
        player2.print(0);
        player1.print(1);
    } else{
        player1.print(0);
        player2.print(1);
    }
}
void GamePvP::initStart(){
    player1.loadDeck();
    player2.loadDeck();
    player1.shuffleDeck();
    player2.shuffleDeck();
    player1.drawThreeCards();
    player2.drawThreeCards();
}
void GamePvP::executeCommands(PlayerLive& src, PlayerLive& trgt){
    while(true){
        printAll();
        string in = src.getInput();
        if(in == "save"){

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

        } else if (in == "play"){
            string ind = src.getInput();
            int index = stoi(ind);
            if(index <= 0 || index > src.handSize() || !(src.playCard(index))){
                cout << "Could not play the requested card." << endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                sleep(5);
                continue;
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