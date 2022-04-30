#include "Player.h"
#include <iostream>
#include <iomanip>
using namespace std;
bool Player::playCard(int NO){
    bool played = board.addToBoard(hand.viewCard(NO));
    if(played){
        hand.playCard(NO);
    } 
    return played;
}
bool Player::attack(int attacking, int defending, PlayingBoard& second){
    if(second.hasTaunt() && !(second.viewCard(defending) -> isTaunt())){
        return false;
    }
    second.getAttacked(board.viewCard(attacking), defending);
    if(board.viewCard(attacking) -> isDead()){
        board.removeCard(attacking);
    }
    return true;
}
void Player::print(unsigned int flag) const{
    if(flag){
        board.print();
        cout << endl;
        hand.print();
        cout << endl;
    } else{
        hand.printCensored();
        cout << endl;
        board.print();
        cout << endl;
    }
}