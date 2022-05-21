#pragma once
#include <iostream>
#include <list>
#include <memory>
using namespace std;
class Player;
/**
 * Effect is an action that is carried out when a Battlecry Card gets played.
 * There are 5 types of Effects in my Game.
 */
class Effect{
public:
    Effect(int st):strength(st){};
    virtual ~Effect(){};
    /**
     * @brief Perform the desired Effect.
     * 
     * @param src Who played the Card
     * @param trgt Who is the enemy
     */
    virtual void doEffect(Player& src, Player& trgt) = 0;
    virtual void printEffect(unsigned int flag) = 0;
    /**
     * @brief Get the length of the desired row of the Effect description.
     * 
     * @param row Description can take up to 2 rows.
     * @return int Length 
     */
    virtual int getLength(int row) = 0;
    /**
     * @brief Returns a smart pointer to a copy of this Object.
     * 
     * @return shared_ptr<Effect> copy
     */
    virtual shared_ptr<Effect> copyPtr() = 0;
    /**
     * @brief prints effectID;strength into out
     * 
     */
    friend ostream& operator <<(ostream& out, const Effect& e){
        e.printOstream(out);
        return out;
    }
protected:
    ///The strength of the Effect.
    int strength;
    list<string> effectDesc;
    virtual void printOstream(ostream& out) const = 0;
};
