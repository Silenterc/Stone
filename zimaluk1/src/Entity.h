#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include <string>
using namespace std;
/**
 * Entity is the base class, from which inherit both Player and a Card.
 */
class Entity{
public:
    /**
     * @brief Construct a new Entity object
     * @param nm Entity name
     * @param hlth Entity health
     * @param dmg  Entity damage
     */
    Entity(const string& nm, int hlth, int dmg = 0):name(nm), health(hlth), damage(dmg){};
    Entity() = default;
    virtual ~Entity() = default;
    bool isDead() const;
    void changeHealth(int change){
        health += change;
    }
    void charge(){
        charged = true;
    }
    void uncharge(){
        charged = false;
    }
    bool isCharged() const{
        return charged;
    }
    string getName() const{
        return name;
    }
    size_t getNameLength() const{
        return name.length();
    }
    int getDamage() const{
        return damage;
    }
    int getHealth() const{
        return health;
    }
    /**
     * @brief Abstract method for printing the piece of info I want to print.
     * 
     * @param flag Tells me which piece of info to print
     */
    virtual void print(unsigned int flag) const = 0; 
protected: 
    string name;  /**Entity name */                                                  
    int health = 0; /**Entity health(0 by default) */                                                    
    int damage = 0; /**Entity damage(0 by default) */
    bool charged = false; //!< If the Entity is a Player, charged means whether he can play a card 
                          //!< If the Entity is a Card, charged means whether it can attack
};
#endif

