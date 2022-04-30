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
bool Player::attack(int attacking, int defending, Player& second){ //return false if the is a Taunt and Player wants to attack smt else
    if(second.board.hasTaunt() && defending == 0){ //0 means that Player wants to attack enemy Player directly, but in this case there is a Taunt in the way
        return false;
    }
    if(defending == 0){
        board.viewCard(attacking) -> attack(second); //FACE!!
        return true;
    }
    if(second.board.hasTaunt() && !(second.board.viewCard(defending) -> isTaunt())){ //another Taunt detection
        return false;
    }
    second.board.getAttacked(board.viewCard(attacking), defending); //card x card combat
    if(board.viewCard(attacking) -> isDead()){ //if the attacker died during combat
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