#include "Card.h"
#include "Deck.h"
#include "Entity.h"
#include "Hand.h"
#include "Player.h"
using namespace std;
#include <iostream>
int main(){
    Deck d;
    TauntCard obr("Obr",3,15);
    BasicCard vojak("Vojak",7,5);
    BattlecryCard silak("Silak",10,5);
    TauntCard megaObr("MegaObr",3,20);
    d.addCard(obr.clonePtr());
    d.addCard(vojak.clonePtr());
    d.addCard(silak.clonePtr());
    d.addCard(megaObr.clonePtr());
    Deck c;
    c = d;
    // assert(d.getSize() == 3);
    // shared_ptr<Card>silakC = d.drawCard();
    // silakC -> printCard(0,0);
    // shared_ptr<Card>vojakC = d.drawCard();
    // shared_ptr<Card>obrC = d.drawCard();
    // vojakC -> printCard(0,0);
    // obrC -> printCard();
    Hand h;
    h.drawCard(c);
    assert(c.getSize() == 3);
    h.drawCard(c);
    assert(c.getSize() == 2);
    int damage = 2;
    h.drawCard(c);
    assert(d.getSize() == 4);
    assert(h.getSize() == 3);
    h.drawCard(c);
    h.print();
    // cout << endl;
    // shared_ptr<Card>silakC = h.getCard(1);
    // silakC -> printCard(0,0);
    // shared_ptr<Card>vojakC = h.getCard(2);
    // vojakC -> printCard(0,0);
    // shared_ptr<Card>obrC = h.getCard(3);
    // obrC -> printCard(0,0);
}