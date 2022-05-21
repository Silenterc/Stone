#pragma once
#include "Effect.h"
class DrawCardEffect : public Effect{
public:
    DrawCardEffect(int s);
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    shared_ptr<Effect> copyPtr() override;
    static shared_ptr<Effect> create(int st){
        return make_shared<DrawCardEffect>(DrawCardEffect(st));
    }
    static constexpr char id[] = "dce";
protected:
    virtual void printOstream(ostream& out) const override;
};