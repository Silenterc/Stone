#pragma once
#include "Effect.h"
class AllDamageEffect : public Effect{
public:
    AllDamageEffect(int s);
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    unique_ptr<Effect> copyPtr() override;
protected:
    virtual void printOstream(ostream& out) const override;
};