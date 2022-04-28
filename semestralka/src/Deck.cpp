#include "Deck.h"
#include <algorithm>
#include <random>
using namespace std;
Deck::Deck(const string& fileName){

}
void Deck::addCard(shared_ptr<Card> crd){
    cards.push_back(crd);
    size++;
}
shared_ptr<Card> Deck::drawCard(){
    if(size == 0){
        throw invalid_argument("Deck is empty");
    }
    shared_ptr<Card> drawn = *(cards.end() - 1);
    cards.pop_back();
    size--;
    return drawn;
}
void Deck::shuffle(){
    auto rng = default_random_engine();
    std::shuffle(cards.begin(),cards.end(),rng);
}


