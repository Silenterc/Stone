#include "Entity.h"
bool Entity::isDead() const{
    if(health <= 0){
        return true;
    }
    return false;
}