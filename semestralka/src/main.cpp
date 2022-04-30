
#include "Player.h"
#include "Menu.h"
using namespace std;
#include <iostream>
int main(){
    Deck d;
    d.loadCards();
    
    // Menu m;
    // m.init();
     /*
    Player p1("Lukas", 30),p2("Sakul", 30);
    Deck d, c;
    TauntCard obr("Obr",3,15);
    BasicCard vojak("Vojak",7,5);
    BattlecryCard silak("Silak",10,5,1);
    BattlecryCard megaSilak("megaSilak",13,6,2);
    TauntCard megaObr("MegaObr",3,20);
    d.addCard(silak.clonePtr());
    d.addCard(megaSilak.clonePtr());
    d.addCard(silak.clonePtr());
    d.addCard(obr.clonePtr());
    d.addCard(vojak.clonePtr());
    d.addCard(silak.clonePtr());
    d.addCard(megaObr.clonePtr());
    c = d;
    p1.setDeck(c);
    p2.setDeck(d);
    for(int i = 0; i < 4; i++){
        p1.drawCard();
        p2.drawCard();
        p1.playCard(1);
        p2.playCard(1);
    }
    p1.drawCard();
    p1.drawCard();
    p2.print(0);
    p1.print(1);
    
    int x,y;
    while(cin >> x >> y){
        cout << "\033[H\033[2J" << flush;
        p1.attack(x,y,p2.getBoard());
        p2.print(0);
        p1.print(1);
    }
    
   
    p2.print(0);
    p1.print(1);
    p1.attack(1,4,p2.getBoard());
    p1.attack(2,4,p2.getBoard());
    p1.attack(3,4,p2.getBoard());
    p1.playCard(1);
    p1.playCard(1);
    p1.playCard(1);
    p1.playCard(1);
    p1.print(0);
    p2.print(1);



    // Deck c = d;
    // h.drawCard(c);
    
    // h.drawCard(c);
    
    // int damage = 2;
    // h.drawCard(c);
   
    // h.drawCard(c);
    // h.print();


    // board1.addToBoard(obr.clonePtr());
    // board1.addToBoard(vojak.clonePtr());
    // board1.addToBoard(silak.clonePtr());
    // board1.addToBoard(megaObr.clonePtr());
    // board2.addToBoard(obr.clonePtr());
    // board2.addToBoard(vojak.clonePtr());
    // board2.addToBoard(silak.clonePtr());
    // board2.addToBoard(megaObr.clonePtr());
    // board1.getAttacked(board2.viewCard(1),2);
    // board1.getAttacked(board2.viewCard(1),2);
    // board1.print();
    // cout << endl;
    // board2.print();
    
    // assert(d.getSize() == 3);
    // shared_ptr<Card>silakC = d.drawCard();
    // silakC -> printCard(0,0);
    // shared_ptr<Card>vojakC = d.drawCard();
    // shared_ptr<Card>obrC = d.drawCard();
    // vojakC -> printCard(0,0);
    // obrC -> printCard();
    // Hand h;
    // h.drawCard(c);
    // assert(c.getSize() == 3);
    // h.drawCard(c);
    // assert(c.getSize() == 2);
    // int damage = 2;
    // h.drawCard(c);
    // assert(d.getSize() == 4);
    // assert(h.getSize() == 3);
    // h.drawCard(c);
    // h.print();
    // cout << endl;
    // shared_ptr<Card>silakC = h.getCard(1);
    // silakC -> printCard(0,0);
    // shared_ptr<Card>vojakC = h.getCard(2);
    // vojakC -> printCard(0,0);
    // shared_ptr<Card>obrC = h.getCard(3);
    // obrC -> printCard(0,0);
    */
}