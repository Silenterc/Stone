#include "Deck.h"
#include <algorithm>
#include <random>
using namespace std;
Deck::Deck(const string& fileName){

}
void Deck::addCard(shared_ptr<Card> crd){
    cards.push_back(crd);
}
shared_ptr<Card> Deck::drawCard(){
    shared_ptr<Card> drawn = *(cards.end());
    cards.pop_back();
    return drawn;
}
void Deck::shuffle(){
    auto rng = default_random_engine();
    std::shuffle(cards.begin(),cards.end(),rng);
}


