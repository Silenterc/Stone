#pragma once
#include "Effect.h"
class BoardDamageEffect : public Effect{
public:
    BoardDamageEffect(int s);
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    shared_ptr<Effect> copyPtr() override;
    static shared_ptr<Effect> create(int st){
        return make_shared<BoardDamageEffect>(BoardDamageEffect(st));
    }
    static constexpr char id[] = "bde";
protected:
    virtual void printOstream(ostream& out) const override;
};