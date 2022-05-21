#ifndef btcr
#define btcr
#include "Card.h"
#include <functional>
/**
 * BattlecryCard is a type of Card, which performs an effect after being played.
 * 
 */
class BattlecryCard : public Card{
public:
    BattlecryCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    bool isTaunt() const override{
        return false;
    }
    bool isBattlecry() const override{
        return true;
    }
    size_t getTypeLength() const override{
        return string("Battlecry").length();
    }
    void print(unsigned int flag = 0) const override;
    int getBattlecryLength(int row) const override; //Works only for 2 rows, which is the maximum length of battlecry description
    shared_ptr<Card> clonePtr() override;
    /**
     * Lets it's effect perform itself on the Players.
     * The effect which is performed is reached by using polymorphism.
     */
    void doBattlecry(Player& src, Player& trgt) override;
    /**
     * @brief Construct the correct effect and set it to be the Card's effect 
     * 
     * @param batID The ID of the effect to be constructed
     * @param str Strength of the effect
     */
    void setEffect(string batID, int str);
    /**
     * Prints it's info and calls it's effect's print function 
     * into out with the final format being Name;Type;Damage;Health;batID;battlecryStrength;charged
     */
    void printOstream(ostream& out) const override;
private:
    static unordered_map<string, function<shared_ptr<Effect>(int)>> effectFactory;
    shared_ptr<Effect> effect;
};
#endif