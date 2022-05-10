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
void Game::printAll() const{
    cout << "\033[H\033[2J" << flush;
    printLines(5);//printing some initial lines
    if(playerTurn){
        player2 -> print(0);
        player1 -> print(1);
    } else{
        player1 -> print(0);
        player2 -> print(1);
    }
}
void Game::play(){
    while(!isDone){
        if(playerTurn){
            player1 -> charge();
            if(!isFirstRound){
                player1 -> drawCard();
            }
            printAll();
            while(int i = player1 -> executeTurn(player2)){
                printAll();
                if(i == 2){
                    saveGame();
                }
            }
            if(player1 -> isDead() || player2 -> isDead()){
                finished();
                return;
            }
            playerTurn = false;
            player2 -> chargeBoard();

        } else{
            player2 -> charge();
            if(!isFirstRound){
                player2 -> drawCard();
            } else{
                isFirstRound = false;
            }
            printAll();
            while(int i = player2 -> executeTurn(player1)){
                printAll();
                if(i == 2){
                    saveGame();
                }
            }
            if(player1 -> isDead() || player2 -> isDead()){
                finished();
                return;
            }
            playerTurn = true;
            player1 -> chargeBoard();
        }
    }
}
void Game::initStartPvP(){
    PlayerLive p1("Player 1", 30);
    PlayerLive p2("Player 2", 30);
    player1 = p1.clonePtr();
    player2 = p2.clonePtr();
    player1 -> loadDeck();
    player2 -> loadDeck();
    player1 -> shuffleDeck();
    player2 -> shuffleDeck();
    player1 -> drawThreeCards();
    player2 -> drawThreeCards();
}
void Game::initStartAI(){
    PlayerLive p1("Player 1", 30);
    PlayerAI p2("Player 2", 30);
    player1 = p1.clonePtr();
    player2 = p2.clonePtr();
    player1 -> loadDeck();
    player2 -> loadDeck();
    player1 -> shuffleDeck();
    player2 -> shuffleDeck();
    player1 -> drawThreeCards();
    player2 -> drawThreeCards();
}
void Game::finished() const{
    cout << "\033[H\033[2J" << flush;
    printLines(5);//printing some initial lines
    printEnd();
    cout << endl;
    cout << endl;
    if(player1 -> isDead() && player2 -> isDead()){
        cout << "It is a draw" << endl;
    } else if(player2 -> isDead()){
        cout << player1 -> getName() <<" has won!" << endl;
    } else{
        cout << player2 -> getName() <<" has won!" << endl; 
    }
    sleep(5);
}
void Game::saveGame() const{
    string fileName = "assets/saves/";
    fileName.append(getLocalTime());
    ofstream saveFile(fileName);
    if(saveFile.fail()){
        throw invalid_argument("Could not create file.");
    }
    saveFile << "PvP" << endl;
    saveFile << playerTurn << endl;
    saveFile << isFirstRound << endl;
    saveFile << *player1;
    saveFile << *player2;
}
void Game::loadGame(ifstream& in, bool isPvP){
    string basInfo;
    getline(in,basInfo);
    playerTurn = stoi(basInfo);
    getline(in,basInfo);
    isFirstRound = stoi(basInfo);
    if(isPvP){
        PlayerLive p1("Player 1", 30);
        PlayerLive p2("Player 2", 30);
        player1 = p1.clonePtr();
        player2 = p2.clonePtr();
    } else{
        PlayerLive p1("Player 1", 30);
        PlayerAI p2("Player 2", 30);
        player1 = p1.clonePtr();
        player2 = p2.clonePtr();
    }
    player1 -> load(in);
    player2 -> load(in);
    playLoaded();
}
void Game::playLoaded(){
    bool justLoaded = true;
    while(!isDone){
        if(playerTurn){
            if(!justLoaded){
                player1 -> charge();
            } 
            if(!isFirstRound && !justLoaded){
                player1 -> drawCard();
            }
            printAll();
            while(int i = player1 -> executeTurn(player2)){
                printAll();
                if(i == 2){
                    saveGame();
                }
            }
            if(player1 -> isDead() || player2 -> isDead()){
                finished();
                return;
            }
            playerTurn = false;
            player2 -> chargeBoard();
        
        } else{
            if(!justLoaded){
                player2 -> charge();
            } 
            
            if(!isFirstRound && !justLoaded){
                player2 -> drawCard();
            }
            if(isFirstRound){
                isFirstRound = false;
            } 
            printAll();
            while(int i = player2 -> executeTurn(player1)){
                printAll();
                if(i == 2){
                    saveGame();
                }
            }
            if(player1 -> isDead() || player2 -> isDead()){
                finished();
                return;
            }
            playerTurn = true;
            player1 -> chargeBoard();
        }
        if(justLoaded){
            justLoaded = false;
        }
    }
}