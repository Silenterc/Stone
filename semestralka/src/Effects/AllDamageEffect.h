#pragma once
#include "Effect.h"
class AllDamageEffect : public Effect{
public:
    AllDamageEffect(int s);
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    shared_ptr<Effect> copyPtr() override;
    static shared_ptr<Effect> create(int st){
        return make_shared<AllDamageEffect>(AllDamageEffect(st));
    }
    static constexpr char id[] = "ade";
protected:
    virtual void printOstream(ostream& out) const override;
};