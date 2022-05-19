#include "Player.h"
#include <iostream>
#include <iomanip>
using namespace std;
void Player::chargeBoard(){
    board.chargeB();
}
void Player::dealDmgOrHealBoard(int change){
    board.getDamagedOrHealed(change);
}
bool Player::playCard(unsigned long NO, Player& enemyPlayer){
    bool canPlay = (!board.isFull() && charged);
    if(canPlay){
        hand.viewCard(NO) -> doBattlecry(*this, enemyPlayer); 
        board.addToBoard(hand.playCard(NO)); 
        uncharge();
    }
    return canPlay;
}
bool Player::attack(int attacking, int defending, Player& second){ //return false if there is a Taunt and Player wants to attack smt else
    if(second.board.hasTaunt() && defending == 0){ //0 means that Player wants to attack enemy Player directly, but in this case there is a Taunt in the way
        return false;
    }
    if(!(board.viewCard(attacking) -> isCharged())){ //the card cannot attack because it isnt charged(was played this round or has attacked)
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
void Player::printNameAndHealth(unsigned int flag) const{
    int spaces = getTermWidth()/2 - getNameLength()/2;
    if(flag){
        printSpaces(spaces);
        cout << health << " health" << endl;
        cout << endl;
        printSpaces(spaces);
        cout << name << endl;
        cout << endl;
    } else{
        printSpaces(spaces);
        cout << name << endl;
        cout << endl;
        printSpaces(spaces);
        cout << health << " health" << endl;
        cout << endl;
    }
}
void Player::print(unsigned int flag) const{
    if(flag){
        board.print();
        cout << endl;
        hand.print();
        cout << endl;
        printNameAndHealth(flag);
    } else{
        printNameAndHealth(flag);
        hand.printCensored();
        cout << endl;
        board.print();
        cout << endl;
    }
}
void Player::loadDeck(ifstream& in){
    deck.loadCards(in);
}
void Player::drawXCards(int x){
    for(int i = 0; i < x; i++){
        hand.drawCard(deck);
    }
}
void Player::doBattlecry(int batID, Player& enemyPlayer){
    switch(batID){
        case 1: drawCard(); //Draw a card and heal 1 health to your hero
                health++;
                return;
        case 2: enemyPlayer.dealDmgOrHealBoard(-2); //Deal 2 damage to the enemy board
                return;
        case 3: dealDmgOrHealBoard(-3); //Deal 3 damage to everyone
                enemyPlayer.dealDmgOrHealBoard(-3);
                health -= 3;
                enemyPlayer.health -= 3;
                return;
        case 4: dealDmgOrHealBoard(2); //Add 2 health to your board and hero
                health += 2;
                return;
        case 5: enemyPlayer.health -= 2; //Deal 2 damage to the enemy hero
                return;
        default: throw invalid_argument("Invalid battlecryID");
    }
}
void Player::printOstream(ostream& out) const{
    out << name << ';' << health << ';' << charged << endl;
    out << deck;
    out << hand;
    out << board;
}
void Player::load(ifstream& in){
    loadInfo(in);
    deck.loadCards(in);
    hand.load(in);
    board.load(in);
}
bool Player::hasTauntOnBoard() const{
    return board.hasTaunt();
}
void Player::loadInfo(ifstream& in){
    string basInfo, pname, phealth, pcharged;
    stringstream parser;
    getline(in, basInfo);
    parser.str(basInfo);
    getline(parser,pname,';');
    getline(parser,phealth,';');
    getline(parser,pcharged,';');
    name = pname;
    health = stoi(phealth);
    charged = stoi(pcharged);
}