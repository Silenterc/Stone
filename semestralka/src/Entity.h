#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include <string>
using namespace std;
class Entity{
public:
    Entity(const string& nm, int hlth, int dmg = 0):name(nm), health(hlth), damage(dmg){};
    virtual ~Entity() = default;
    bool isDead() const;
    void changeHealth(int change){
        health += change;
    }
    virtual void charge(){
        charged = true;
    }
    virtual void uncharge(){
        charged = false;
    }
    virtual bool isCharged() const{
        return charged;
    }
    string getName() const{
        return name;
    }
    size_t getNameLength() const{
        return name.length();
    }
    virtual void print(unsigned int flag) const = 0; //the flag tells what piece of info to print
protected:                                                          // f.e I want to print Soldier         Giant    ...
    string name;                                                    //                     7 damage        2 damage
    int health;                                                     //                     4 health        10 health
    int damage; 
    bool charged = false;
    friend class Card; //When a card attacks a player, it should be able to change his health => has to be friend
};
#endif

