#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include <string>
using namespace std;
class Entity{
public:
    Entity(const string& nm, int hlth, int dmg = 0):name(nm), health(hlth), damage(dmg){};
    virtual ~Entity() = default;
    bool isDead();
    string getName(){
        return name;
    }
    virtual void printCard(unsigned int flag, int spaces) const = 0; //the flag tells what piece of info to print
protected:                                                          // f.e I want to print Soldier         Giant    ...
    string name;                                                    //                     7 damage        2 damage
    int health;                                                     //                     4 health        10 health
    int damage; 
    friend class Card; //When a card attacks a player, it should be able to change his health => has to be friend
};
#endif

