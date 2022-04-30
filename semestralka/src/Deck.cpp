#include "Deck.h"
#include <algorithm>
#include <random>
using namespace std;
Deck::Deck(const string& fileName){

}
Deck& Deck::operator =(const Deck& second){
    if(this == &second){
        return *this;
    }
    cards.clear();
    for(auto& c : second.cards){
        cards.push_back(c -> clonePtr());
    }
    size = second.size;
    return *this;
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
void Deck::loadCards(){
    
}


