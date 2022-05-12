#pragma once
#include <iostream>
#include <list>
#include <memory>
using namespace std;
class Player;
class Effect{
public:
    Effect(int st):strength(st){};
    virtual ~Effect(){};
    virtual void doEffect(Player& src, Player& trgt) = 0;
    virtual void printEffect(unsigned int flag) = 0;
    virtual int getLength(int row) = 0;
    virtual shared_ptr<Effect> copyPtr() = 0;
    friend ostream& operator <<(ostream& out, const Effect& e){
        e.printOstream(out);
        return out;
    }
protected:
    int strength;
    list<string> effectDesc;
    virtual void printOstream(ostream& out) const = 0;
};
