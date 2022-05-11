#pragma once
#include <iostream>
#include <list>
using namespace std;
class Player;
class Effect{
public:
    Effect(int st):strength(st){};
    virtual ~Effect(){};
    virtual void doEffect(Player& src, Player& trgt) = 0;
    virtual void printEffect(unsigned int flag) = 0;
    virtual int getLength(int row) = 0;
    virtual unique_ptr<Effect> copyPtr() = 0;
    friend ostream& operator <<(ostream& out, const Effect& e){
        e.printOstream(out);
        return out;
    }
protected:
    int strength;
    list<string> effectDesc;
    virtual void printOstream(ostream& out) const = 0;
};
class DrawCardEffect : public Effect{
public:
    DrawCardEffect(int s);
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    unique_ptr<Effect> copyPtr() override;
protected:
    virtual void printOstream(ostream& out) const override;
};
class BoardDamageEffect : public Effect{
public:
    BoardDamageEffect(int s);
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    unique_ptr<Effect> copyPtr() override;
protected:
    virtual void printOstream(ostream& out) const override;
};
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
class HealBoardEffect : public Effect{
public:
    HealBoardEffect(int s);
    void doEffect(Player& src, Player& trgt) override;
    void printEffect(unsigned int flag) override;
    int getLength(int row) override;
    unique_ptr<Effect> copyPtr() override;
protected:
    virtual void printOstream(ostream& out) const override;
};
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