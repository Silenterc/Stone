#include "Player.h"
using namespace std;
pair<string, bool> Player::drawCard(){
    return hand.drawCard(deck);
}