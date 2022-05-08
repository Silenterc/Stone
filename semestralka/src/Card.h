#pragma once
#ifndef CARD_H
#define CARD_H
#include "Entity.h"
#include "helperFunc.h"
#include <list>
class Card : public Entity{
public:
    Card(const string& nm, int dmg, int hlth):Entity(nm, hlth, dmg){};
    bool attack(Entity& second);
    size_t getDamageLength() const;
    size_t getHealthLength() const;
    void changeHealth(int change){
        health += change;
    }
    virtual bool isBattlecry() const = 0;
    virtual bool isTaunt() const = 0;
    virtual size_t getTypeLength() const = 0; //string length of the type (for printing purposes)
    virtual int getBattlecry() const = 0; //each battlecry effect has its int ID, from which I will deduct the effect. Returns 0 if the card is not a battlecry.
    virtual int getBattlecryLength(int batNO, int row) const = 0;
    virtual shared_ptr<Card> clonePtr() = 0;
    friend ostream& operator <<(ostream& out, const Card& crd){
        crd.printOstream(out);
        return out;
    }
protected:
    virtual void printOstream(ostream& out) const = 0;
private:
};
class BasicCard : public Card{
public:
    BasicCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    bool isBattlecry() const override{
        return false;
    }
    bool isTaunt() const override{
        return false;
    }
    size_t getTypeLength() const override{
        return string("Basic Card").length();
    }
    void print(unsigned int flag = 0) const override;
    int getBattlecry() const override{
        return 0;
    }
    int getBattlecryLength(int batNO, int row) const override{
        return 0;
    }
    shared_ptr<Card> clonePtr() override;
    void printOstream(ostream& out) const override;
private:
};
class TauntCard : public Card{
public:
    TauntCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    bool isBattlecry() const override{
        return false;
    }
    bool isTaunt() const override{
        return true;
    }
    size_t getTypeLength() const override{
        return string("Taunt").length();
    }
    void print(unsigned int flag = 0) const override;
    int getBattlecry() const override{
        return 0;
    }
    int getBattlecryLength(int batNO, int row) const override{
        return 0;
    }
    shared_ptr<Card> clonePtr() override;
    void printOstream(ostream& out) const override;
private:
};
class BattlecryCard : public Card{
public:
    BattlecryCard(const string& nm, int dmg, int hlth, int batNO):Card(nm, dmg, hlth),battlecryID(batNO){};
    bool isBattlecry() const override{
        return true;
    }
    bool isTaunt() const override{
        return false;
    }
    size_t getTypeLength() const override{
        return string("Battlecry").length();
    }
    void print(unsigned int flag = 0) const override;
    int getBattlecry() const override{
        return battlecryID;
    }
    int getBattlecryLength(int batNO, int row) const override; //Works only for 2 rows, which is the maximum length of battlecry description
    shared_ptr<Card> clonePtr() override;
    void printOstream(ostream& out) const override;
private:
    int battlecryID; //identifier of which battlecry effect does the card have. Starts from 1.
};
#endif