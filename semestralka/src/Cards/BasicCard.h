#ifndef bscr
#define bscr
#include "Card.h"
/**
 * This type of Card does not have any special powers.
 * 
 */
class BasicCard : public Card{
public:
    BasicCard(const string& nm, int dmg, int hlth):Card(nm, dmg, hlth){};
    bool isTaunt() const override{
        return false;
    }
    bool isBattlecry() const override{
        return false;
    }
    size_t getTypeLength() const override{
        return string("Basic Card").length();
    }
    void print(unsigned int flag = 0) const override;
    int getBattlecryLength(int row) const override{
        return 0;
    }
    shared_ptr<Card> clonePtr() override;
    /**
     * @brief It is not a Battlecry Card, so it does nothing
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