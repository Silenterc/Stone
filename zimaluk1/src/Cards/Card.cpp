#include "Card.h"
#include "../Player.h"
bool Card::attack(Entity& second){
    if(!charged){
        return false;
    }
    second.changeHealth(-damage);
    health -= second.getDamage();
    uncharge();
    return true;
}
size_t Card::getDamageLength() const{
    return (to_string(damage)).length();
}
size_t Card::getHealthLength() const{
    return (to_string(health)).length();
}

