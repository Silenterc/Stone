#ifndef tntc
#define tntc
#include "Card.h"
/**
 * A Taunt Card has the highest priority when it is on the Board.
 * That means that you must attack it first.
 */
class TauntCard : public Card{
public:
    TauntCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    bool isTaunt() const override{
        return true;
    }
    bool isBattlecry() const override{
        return false;
    }
    size_t getTypeLength() const override{
        return string("Taunt").length();
    }
    void print(unsigned int flag = 0) const override;
    int getBattlecryLength(int row) const override{
        return 0;
    }
    shared_ptr<Card> clonePtr() override;
    /**
     * @brief Does not to anything.
     * 
     */
    void doBattlecry(Player& src, Player& trgt) override;
    /**
     * Prints itself into out in the format Name;Type;Damage;Health;batID;battlecryStrengthcharged 
     * where batID and battlecryStrength are 0
     */
    void printOstream(ostream& out) const override;
private:
};
#endif