#include "PlayerAI.h"
unique_ptr<Player> PlayerAI::clonePtr(){
    return make_unique<PlayerAI>(*this);
}
int PlayerAI::executeTurn(unique_ptr<Player>& trgt){
    clearBoard(trgt);
    //tryGetLethal(trgt);
    //tryPreventLethal(trgt);
    return 0;
}
void PlayerAI::clearBoard(unique_ptr<Player>& trgt){
    int bestValue = INT_MIN;
    bool hasBasicAttacked = false; //I only need to call attackRec once for all the cards that are not Battlecry(the outcome would always be the same)
    PlayerAI bestAI;
    unique_ptr<Player> bestEnemy;
    for(size_t i = 0; i <= handSize(); i++){ //We try out different scenarios for each played Card
        PlayerAI ai = *this;
        unique_ptr<Player> enemy = trgt -> clonePtr();
        if(i == 0){ //For when I dont play a card
            unsigned long indexToAttack = enemy -> getBoard().getTauntIndex(); //The AI attacks Taunts first
            while(indexToAttack != 0){
               if(!attackOne(ai, enemy, enemy -> getBoard(), indexToAttack)){ //If we cannot attack anymore
                   break;
               }
               indexToAttack = enemy -> getBoard().getTauntIndex();
            }
            while(attackOne(ai, enemy, enemy -> getBoard(), 1)){ //If there are no Taunts left, attack the first Card on the Board
            }
        } else if(ai.hand.viewCard(i) -> isBattlecry()){ //We play Battlecry and then attack
            ai.playCard(i, *enemy);
            unsigned long indexToAttack = enemy -> getBoard().getTauntIndex();
            while(indexToAttack != 0){
               if(!attackOne(ai, enemy, enemy -> getBoard(), indexToAttack)){
                   break;
               }
               indexToAttack = enemy -> getBoard().getTauntIndex();
            }
            while(attackOne(ai, enemy, enemy -> getBoard(), 1)){  
            }
   
        } else{
            if(!hasBasicAttacked){ //For Cards that dont have any special effects, we only have to explore the options once
                hasBasicAttacked = true;
                unsigned long indexToAttack = enemy -> getBoard().getTauntIndex();
                while(indexToAttack != 0){
                    if(!attackOne(ai, enemy, enemy -> getBoard(), indexToAttack)){
                        break;
                    }
                    indexToAttack = enemy -> getBoard().getTauntIndex();
                }  
                while(attackOne(ai, enemy, enemy -> getBoard(), 1)){
                }
            }
            ai.playCard(i, *enemy); //And try to play the desired Card last
        }
        if(ai.isDead()){ //This definitely is not a good Evaluation
            continue;
        }
        int currValue = ai.board.getValue() - enemy -> getBoard().getValue(); //Evaluate the current Board status
        if(currValue > bestValue){ //If the evaluation is better than the best so far, we update the best
            bestAI = move(ai);
            bestEnemy = move(enemy);
            bestValue = currValue;
        }
    }
    *this = move(bestAI); //We make the best Board turn possible
    trgt = move(bestEnemy);
}
bool PlayerAI::attackOne(PlayerAI& src, unique_ptr<Player>& trgt, PlayingBoard& enemyB, unsigned long index){
    if(src.board.isUncharged()){ //There is no reason to continue if none of the Cards can attack
        return false;
    }
    if(enemyB.getSize() == 0){  //Will go face if the enemy Board is clear
        for(size_t i = 1; i <= src.boardSize(); i++){
            src.attack( i, 0, *trgt);
        }
        return false;
    }
    // trgt -> print(0);
    // src.print(1);
    vector <unsigned long> indexes; //Vector to store our permuted indexes, in which order we will attack
    pair <int, vector<unsigned long>> bestMoves; //pair of <amount of attacking moves, indexes in the correct order> of the best attack combination
    int currBest = INT_MIN; //will be used to store, compare and evaluate the best Board state
    for(size_t i = 1; i <= src.board.getSize(); i++){ //Fill the indexes Vector
        indexes.push_back(i);
    }
    PlayingBoard myBoard;
    PlayingBoard enemyBoard = enemyB;
    int moves = 0; //The amount of moves=attacks my Cards do 
    do{
        myBoard = src.board;
        shared_ptr<Card> enemyCard = enemyBoard.viewCard(index) -> clonePtr();
        moves = 0;
        for(unsigned long i : indexes){
           if((myBoard.viewCard(i) -> attack(*enemyCard))){ //The Cards attack in the permutated order
               moves++;
           }
           if(enemyCard -> isDead()) break; //If the target Card has been killed, we should not attack it anymore
        }
        int eval = evalOne(enemyCard, myBoard); // Evaluate the Board
        if((eval > currBest) && moves != 0){ //Compare the best Evaluation with the current one, and update if necessary
            currBest = eval;
            bestMoves.first = moves;
            bestMoves.second = indexes;
        }
    }while(next_permutation(indexes.begin(),indexes.end())); //Here we permute the order in which the Cards attack
    int id = 0; 
    for(int i = 0; i < bestMoves.first;){ //Carry out the best possible attack combination
        if(src.attack(bestMoves.second[id], index, enemyB)){
            i++;
        }
        id++;
    }
    return true;

}
int PlayerAI::evalOne(shared_ptr<Card> enemyCard, PlayingBoard& friendlyBoard){
    return friendlyBoard.getValue() - enemyCard -> getValue();
}

bool PlayerAI::hasLethal(const PlayerAI& ai, unique_ptr<Player>& trgt) const{
    if(ai.board.combinedDamage() >= trgt -> getHealth() && !(trgt -> hasTauntOnBoard())){
        return true;
    }
    return false;
}