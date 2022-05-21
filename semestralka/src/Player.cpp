#include "Player.h"
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
bool Player::attack(unsigned long attacking, unsigned long defending, Player& second){ //return false if there is a Taunt and Player wants to attack smt else
    if(attacking <= 0 || attacking > board.getSize() || defending > second.board.getSize()){ //Out of Bounds
        return false;
    }
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
bool Player::attack(unsigned long attacking, unsigned long defending, PlayingBoard& second){
    if(attacking <= 0 || attacking > board.getSize() || defending > second.getSize()){ //Out of Bounds
        cout << "erorr" << endl;
        return false;
    }
    if(!(board.viewCard(attacking) -> isCharged())){ //the card cannot attack because it isnt charged(was played this round or has attacked)
        return false;
    }
    if(second.hasTaunt() && !(second.viewCard(defending) -> isTaunt())){ //another Taunt detection
        return false;
    }
    second.getAttacked(board.viewCard(attacking), defending); //card x card combat
    return true;
}
void Player::printInfo(unsigned int flag) const{
    int spaces = getTermWidth()/2 - getNameLength()/2;
    if(flag){
        printSpaces(spaces);
        cout << health << " health" << endl;
        printSpaces(spaces);
        cout << "deck: " << deck.getSize() << endl;
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
        printSpaces(spaces);
        cout << "deck: " << deck.getSize() << endl;
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
bool Player::noCardsLeft() const{
    return (deck.isEmpty() && hand.isEmpty() && board.isEmpty());
}