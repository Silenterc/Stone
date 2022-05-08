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
    auto rd = std::random_device();
    auto rng = default_random_engine(rd());
    std::shuffle(cards.begin(),cards.end(),rng);
}
void Deck::loadCards(ifstream& in){
    string cardLine;
    stringstream parser;
    string cardAmount, cardName, cardType, damage, health, battlecryID, charged;
    getline(in, cardLine); //Get the size of the deck
    parser.str(cardLine);
    getline(parser,cardAmount,';');
    int amount = stoi(cardAmount);
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
        getline(parser,charged,';');
        if(cardType == "Basic Card"){
            BasicCard newOne(cardName, stoi(damage), stoi(health));
            if(charged == "1"){
                newOne.charge();
            }
            addCard(newOne.clonePtr());
        } else if(cardType == "Taunt"){
            TauntCard newOne(cardName, stoi(damage), stoi(health));
            if(charged == "1"){
                newOne.charge();
            }
            addCard(newOne.clonePtr());
        } else if(cardType == "Battlecry"){
            BattlecryCard newOne(cardName, stoi(damage), stoi(health), stoi(battlecryID));
            if(charged == "1"){
                newOne.charge();
            }
            addCard(newOne.clonePtr());
        } else{
            throw invalid_argument("Invalid card type");
        }
    }
}
void Deck::printOstream(ostream& out) const{
    out << size << ';' << endl;
    for(const auto& c : cards){
        out << *c << endl;
    }
}


