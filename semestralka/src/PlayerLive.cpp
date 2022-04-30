#include "PlayerLive.h"

stringstream PlayerLive::getInput(){
    string in;
    cin >> in;
    stringstream s;
    s.str(in);
    return s;
}