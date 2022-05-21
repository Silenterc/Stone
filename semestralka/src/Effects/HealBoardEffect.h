#pragma once
#include "Effect.h"
/**
 * @brief Heals the Board of the Player who plays this Effect.
 * 
 */
class HealBoardEffect : public Effect{
public:
    HealBoardEffect(int s);
    /**
     * Adds strength-amount of health to every Card on the src Player's Board
     * 
     */
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    shared_ptr<Effect> copyPtr() override;
    static shared_ptr<Effect> create(int st){
        return make_shared<HealBoardEffect>(HealBoardEffect(st));
    }
    static constexpr char id[] = "hbe";
protected:
    virtual void printOstream(ostream& out) const override;
};