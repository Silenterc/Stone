#pragma once
#ifndef CARD_H
#define CARD_H
#include "Entity.h"
class Card : public Entity{
public:
    Card(const string& nm, int dmg, int hlth):Entity(nm, dmg, hlth){};
    bool attack(Entity& second);
    virtual void printCard(unsigned int flag, int spaces) const = 0;
    virtual shared_ptr<Card> clonePtr() = 0;
protected:
    
};
class BasicCard : public Card{
public:
    BasicCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    void printCard(unsigned int flag, int spaces) const override;
    shared_ptr<Card> clonePtr() override;
private:
};
class TauntCard : public Card{
public:
    TauntCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    void printCard(unsigned int flag, int spaces) const override;
    shared_ptr<Card> clonePtr() override;
private:
};
class BattlecryCard : public Card{
public:
    BattlecryCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    void printCard(unsigned int flag, int spaces) const override;
    shared_ptr<Card> clonePtr() override;
private:
};
#endif