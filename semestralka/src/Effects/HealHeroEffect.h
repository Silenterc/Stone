#pragma once
#include "Effect.h"
/**
 * @brief Heals the Player who plays this Effect.
 * 
 */
class HealHeroEffect : public Effect{
public:
    HealHeroEffect(int s);
    /**
     * @brief Adds strength-amount of health to src Player.
     * 
     */
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    shared_ptr<Effect> copyPtr() override;
    static shared_ptr<Effect> create(int st){
        return make_shared<HealHeroEffect>(HealHeroEffect(st));
    }
    static constexpr char id[] = "hhe";
protected:
    virtual void printOstream(ostream& out) const override;
};