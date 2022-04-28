#include <string>
using namespace std;
class Entity{
public:
    Entity(const string& nm, int dmg, int hlth = 0):name(nm), damage(dmg), health(hlth){};
    virtual ~Entity() = default;
    bool isDead();
    virtual void printCard(unsigned int flag, int spaces) const = 0; //the flag tells what piece of info to print
protected:                                                          // f.e I want to print Soldier         Giant    ...
    string name;                                                    //                     7 damage        2 damage
    int health;                                                     //                     4 health        10 health
    int damage; 
    friend class Card; //When a card attacks a player, it should be able to change his health => has to be friend
};

