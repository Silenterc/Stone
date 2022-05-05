#include "Deck.h"
#include <algorithm>
#include <random>
using namespace std;
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
void Deck::loadCards(ifstream& in, int amount){
    string cardLine;
    stringstream parser;
    string cardName, cardType, damage, health, battlecryID;
    for(int i = 0; i < amount; i++){
        cardLine.clear();
        parser.clear();
        getline(in,cardLine);
        parser.str(cardLine);
        getline(parser,cardName,';');
        getline(parser,cardType,';');
        getline(parser,damage,';');
        getline(parser,health,';');
        getline(parser,battlecryID,';');
        if(cardType == "Basic Card"){
            BasicCard newOne(cardName, stoi(damage), stoi(health));
            addCard(newOne.clonePtr());
        } else if(cardType == "Taunt"){
            TauntCard newOne(cardName, stoi(damage), stoi(health));
            addCard(newOne.clonePtr());
        } else if(cardType == "Battlecry"){
            BattlecryCard newOne(cardName, stoi(damage), stoi(health), stoi(battlecryID));
            addCard(newOne.clonePtr());
        } else{
            throw invalid_argument("Invalid card type");
        }
    }

}


