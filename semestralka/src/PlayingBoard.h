#ifndef BOARD_H
#define BOARD_H
#include <Card.h>
using namespace std;
class PlayingBoard(){
public:
private:
    vector< shared_ptr<Card> > cards;
};
#endif