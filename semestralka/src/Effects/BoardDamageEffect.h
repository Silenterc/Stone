#pragma once
#include "Effect.h"
class BoardDamageEffect : public Effect{
public:
    BoardDamageEffect(int s);
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    shared_ptr<Effect> copyPtr() override;
protected:
    virtual void printOstream(ostream& out) const override;
};