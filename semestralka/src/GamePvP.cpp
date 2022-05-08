#include "GamePvP.h"
using namespace std;
void GamePvP::play(){
    initStart();
    bool isFirstRound = true;
    while(!isDone){
        if(playerTurn){
            player1.charge();
            if(!isFirstRound){
                player1.drawCard();
            }
            printAll();
            executeCommands(player1, player2);
            if(player1.isDead() || player2.isDead()){
                finished();
                return;
            }
            playerTurn = false;
            player2.chargeBoard();
        
        } else{
            player2.charge();
            if(!isFirstRound){
                player2.drawCard();
            } else{
                isFirstRound = false;
            }
            printAll();
            executeCommands(player2, player1);
            if(player1.isDead() || player2.isDead()){
                finished();
                return;
            }
            playerTurn = true;
            player1.chargeBoard();
        }
    }
}
void GamePvP::printAll() const{
    cout << "\033[H\033[2J" << flush;
    printLines(5);//printing some initial lines
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
            if(player1.isDead() || player2.isDead()){
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
            if(player1.isDead() || player2.isDead()){
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
void GamePvP::finished() const{
    cout << "\033[H\033[2J" << flush;
    printLines(5);//printing some initial lines
    printEnd();
    cout << endl;
    cout << endl;
    if(player1.isDead() && player2.isDead()){
        cout << "It is a draw" << endl;
    } else if(player2.isDead()){
        cout << player1.getName() <<" has won!" << endl;
    } else{
        cout << player2.getName() <<" has won!" << endl; 
    }
    sleep(5);
}