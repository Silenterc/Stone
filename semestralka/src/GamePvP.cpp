#include "GamePvP.h"
using namespace std;
void GamePvP::play(){
    initStart();
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
void GamePvP::saveGame() const{
    string fileName = "assets/saves/";
    fileName.append(getLocalTime());
    ofstream saveFile(fileName);
    if(saveFile.fail()){
        throw invalid_argument("Could not create file.");
    }
    saveFile << "PvP" << endl;
    saveFile << playerTurn << endl;
    saveFile << isFirstRound << endl;
    saveFile << player1;
    saveFile << player2;
}
void GamePvP::loadGame(ifstream& in){
    string basInfo;
    getline(in,basInfo);
    playerTurn = stoi(basInfo);
    getline(in,basInfo);
    isFirstRound = stoi(basInfo);
    cout << "Loaded info" << endl;
    player1.load(in);
    player2.load(in);
    playLoaded();
}
void GamePvP::playLoaded(){
    bool justLoaded = true;
    while(!isDone){
        if(playerTurn){
            if(!justLoaded){
                player1.charge();
            } 
            if(!isFirstRound && !justLoaded){
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
            if(!justLoaded){
                player2.charge();
            } 
            
            if(!isFirstRound && !justLoaded){
                player2.drawCard();
            }
            if(isFirstRound){
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
        if(justLoaded){
            justLoaded = false;
        }
    }
}