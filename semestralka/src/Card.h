#include "Entity.h"
class Card : public Entity{
public:
    Card(const string& nm, int dmg, int hlth):Entity(nm, dmg, hlth){};
    bool attack(Entity& second);
    virtual void printCard(unsigned int flag, int spaces) const = 0;
protected:
    
};
class BasicCard : public Card{
public:
    BasicCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    void printCard(unsigned int flag, int spaces) const override;
private:
};
class TauntCard : public Card{
public:
    TauntCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    void printCard(unsigned int flag, int spaces) const override;
private:
};
class BattlecryCard : public Card{
public:
    BattlecryCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    void printCard(unsigned int flag, int spaces) const override;
private:
};