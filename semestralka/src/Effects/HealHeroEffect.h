#pragma once
#include "Effect.h"
class HealHeroEffect : public Effect{
public:
    HealHeroEffect(int s);
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    unique_ptr<Effect> copyPtr() override;
protected:
    virtual void printOstream(ostream& out) const override;
};