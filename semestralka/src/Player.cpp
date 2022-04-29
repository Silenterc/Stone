#include "Player.h"
#include <iostream>
#include <iomanip>
using namespace std;
void Player::attack(int attacking, int defending, Player& second){
    second.board.getAttacked(board.viewCard(attacking), defending);
    if(board.viewCard(attacking) -> isDead()){
        board.removeCard(attacking);
    }
}
void Player::print(unsigned int flag) const{
    if(flag){
        board.print();
        hand.print();
    } else{
        //COMING SOON
    }
}