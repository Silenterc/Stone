#include "Player.h"
#include <iostream>
#include <iomanip>
using namespace std;
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
    } else{
        board.print();
        cout << endl;
        hand.printCensored();
    }
}