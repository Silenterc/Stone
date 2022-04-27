#include "Entity.h"
bool Entity::isDead(){
    if(health <= 0){
        return true;
    }
    return false;
}