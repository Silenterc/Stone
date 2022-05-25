#ifndef AI
#define AI
#include "Player.h"
/**
 * @brief A Player controlled by my AI.
 * The AI always attacks the enemy Card with the highest priority.
 * It attacks the enemy Player directly only if he has got no cards left on Board.
 * 
 */
class PlayerAI : public Player{
public:
    PlayerAI(const string& nm,int hlth) : Player(nm, hlth){};
    PlayerAI() = default;
    unique_ptr<Player> clonePtr() override;
    /**
     * @brief A function that carries out the AI's turn.
     * 
     * @return int always returns 0, because the AI performs whole the turn in one call
     */
    int executeTurn(unique_ptr<Player>& trgt) override;
    /**
     * @brief Does nothing, because the AI is not an alive Player.
     * 
     */
    void printConfirmation() const override{};
    void print(unsigned int flag) const override;
protected:
    /**
     * @brief This function performs the optimal turn.
     * For every Card from the Hand it tries to play it and then evaluates what the best 
     * Card to be played in combination with the best Board attacking scenario is and
     * performs the best situation.
     * 
     * @param trgt 
     */
    void clearBoard(unique_ptr<Player>& trgt);
    /**
     * Function that evaluates and performs the best permutation of the order of friendly Cards 
     * attacking an enemy Card(or Player) at index.
     * 
     * @param src A copy of this AI Player
     * @param trgt A pointer to the Enemy Player
     * @param enemyB A copy of the Enemy Board
     * @param index Index of the Card to be attacked
     * @return true 
     * @return false 
     */
    bool attackOne(PlayerAI& src, unique_ptr<Player>& trgt, PlayingBoard& enemyB, unsigned long index);
    /**
     * @brief Evaluates the state of the friendly Board and enemyCard
     * 
     */
    int evalOne(shared_ptr<Card> enemyCard, PlayingBoard& friendlyBoard);
    /**
     * @brief Calls attackOne() until the Cards cannot attack anymore
     * 
     */
    void performAttacking(PlayerAI& src, unique_ptr<Player>& trgt);
};
#endif