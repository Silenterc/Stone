
#ifndef CARD_H
#define CARD_H
#include "../helperFunc.h"
#include "../Entity.h"
#include "../Effects/AllDamageEffect.h"
#include "../Effects/BoardDamageEffect.h"
#include "../Effects/DrawCardEffect.h"
#include "../Effects/HealBoardEffect.h"
#include "../Effects/HealHeroEffect.h"
#include <list>
#include <iostream>
#include <unordered_map>
/**
 * Card is the main component of this game.
 * It is an abstract class, from which inherit different types of Cards.
 */
class Card : public Entity{
public:
    Card(const string& nm, int dmg, int hlth):Entity(nm, hlth, dmg){};
    Card() = default;
    /**
     * @brief Performs an attack from a Card against an Entity(Plaer or Card)
     * @param second The enemy Entity
     * @return true Attack was succesful(= Card is charged)
     * @return false Card was not charged
     */
    bool attack(Entity& second);
    /**
     * @brief Get the length of the Card's damage as a string 
     * @return length of damage 
     */
    size_t getDamageLength() const;
    /**
     * @brief Get the length of the Card's health as a string
     * @return length of health 
     */
    size_t getHealthLength() const;
    /**
     * @brief Get the percieved value of the Card.
     * If the Card is dead, the value is 0.
     * Else, the value is damage + health
     * @return value of the Card 
     */
    int getValue() const{
        if(isDead()){
            return 0;
        }
        return damage + health;
    }
    /**
     * @brief Adds the change parameter to the Card's health variable. 
     * @param change The amount by which I should change the health.
     */
    void changeHealth(int change){
        health += change;
    }
    /**
     * @brief Check whether the Card is a Taunt  
     * @return true It is a Taunt
     * @return false It is not a Taunt
     */
    virtual bool isTaunt() const = 0;
    /**
     * @brief Check whether the Card is a Battlecry 
     * @return true It is a Battlecry
     * @return false It is not a Battlecry
     */
    virtual bool isBattlecry() const = 0;
    /**
     * @brief Get the length of the type as string(for printing purposes)
     * 
     * @return size_t length of the Type 
     */
    virtual size_t getTypeLength() const = 0; 
    /**
     * @brief Get the length of the Battlecry effect description at a certain row(for printing purposes)
     * f.e. The Effect can be: Deal 2 damage to
     *                         the enemy board
     * Which is 2 rows long
     * @param row The row of the description
     * @return size_t length of the Type 
     */
    virtual int getBattlecryLength(int row) const = 0;
    /**
     * @brief Creates a shared pointer to the Card
     * 
     * @return shared_ptr<Card> new copy
     */
    virtual shared_ptr<Card> clonePtr() = 0;
    /**
     * @brief Polymorphically carries out the Battlecry Effect, if there is one
     * @param src Player who played the Card
     * @param trgt Enemy Player
     */
    virtual void doBattlecry(Player& src, Player& trgt) = 0;
    /**
     * @brief Overloaded << operator used for saving the Card into a file
     * The Card is saved in the format: Name;Type;Damage;Health;battlecryID;battlecryStrength;charged
     * @param out ostream
     * @param crd Card to be printed
     * @return ostream& 
     */
    friend ostream& operator <<(ostream& out, const Card& crd){
        crd.printOstream(out);
        return out;
    }
protected:
    /**
     * @brief Abstract method to correctly put the Card info into the ostream&
     * 
     * @param out Here the Card will be written into
     */
    virtual void printOstream(ostream& out) const = 0;
private:
};
#endif