
#include "Menu.h"
using namespace std;
#include <iostream>
int main(){
    // BattlecryCard d("n",4,5);
    // d.setEffect("dce", 1);
    // cout <<"here" << endl;
    // d.setEffect("ade", 1);
    // cout <<"here" << endl;
    // d.setEffect("hbe", 1);
    // cout <<"here" << endl;
    // d.setEffect("hhe", 1);
    // cout <<"here" << endl;
    // d.setEffect("bde", 1);
    // cout <<"here" << endl;
      Menu m;
      m.init();
    //   Deck a, b;
    //   PlayerAI test("ne", 30);
    //   PlayerLive tstp("jo", 1);
    //   ifstream in = loadFile("assets/loadTest");
    //   test.load(in);
    //   cout << "Here" << endl;
    //   tstp.load(in);
    //   unique_ptr<Player> jo = tstp.clonePtr();
    // //   test.shuffleDeck();
    // //   jo -> shuffleDeck();
    //   jo -> drawCard();
    //   jo -> drawCard();
    // //   jo -> drawCard();
    // //   jo -> drawCard();
    // //   jo -> playCard(1,test);
    //   jo -> charge();
    //   jo -> playCard(1,test);
    //   jo -> charge();
    //   jo -> playCard(1,test);
    // //   jo -> charge();
    // //   jo -> playCard(1,test);
    // // //   jo -> charge();
    // // //   jo -> playCard(1,test);
    // // //   jo -> charge();
    // // //    jo -> playCard(1,test);
    // //   test .  drawCard();
    // //   test . drawCard();
    // //   test . drawCard();
    //   test . drawCard();
    // //   test . drawCard();
    //   test . playCard(1,*jo);
    //   test.charge();
    //   test . playCard(1,*jo);
    //   test.charge();
    // //   test . playCard(1,*jo);
    // //   test.charge();
    // //   test . drawCard();
    // //   test . drawCard();
    // //   test . playCard(1,*jo);
    // //   test.charge();
    // //   test . playCard(1,*jo);
    // //   test.charge();
    // //   test . playCard(1,*jo);
    // //   test . playCard(1,*jo);
    //   jo ->print(0);
    //   test . print(1);
    //   test.chargeBoard();
    //   test.charge();
    //   test.executeTurn(jo);
    //   jo ->print(0);
    //   test . print(1);
      
//    DrawCardEffect d(1);
//    HealHeroEffect h(2);
//    BattlecryCard silak("Silak",10,5);
//    BattlecryCard test("Test",10,5);
//    silak.setEffect("dce", 1);
//    test.setEffect("hhe", 2);
//    shared_ptr<Card> e = silak.clonePtr();
//    cout << e ->getBattlecryLength(1) << endl;
//    BattlecryCard ee(silak);
//    cout << ee.getBattlecryLength(1) << endl;
//    cout << ee.getBattlecryLength(2) << endl;
//    d.printEffect(1);
//    cout << endl;
//    d.printEffect(2);
//    cout << endl;
//    h.printEffect(1);
//    cout << endl;
//    h.printEffect(2);
//    cout << endl;
//    PlayerLive p1("",30);
//    unique_ptr<Player> p = p1.clonePtr();
//    p -> loadDeck();
//    cout << p ->deckSize() << endl;
//    cout << p ->drawCard().first << endl;
//    cout << p ->drawCard().first << endl;
//    cout << p ->drawCard().first << endl;
//    cout << p ->drawCard().first << endl;
//    cout << p -> handSize() << endl;
//    d.doEffect(p,p);
//    cout << p -> handSize() << endl;
    
    //  GamePvP game;
    //  //game.saveGame();
    //  game.play();
    
    // Deck d;
    // string path("assets/cards");
    // ifstream in = loadFile(path);
    // d.loadCards(in);
    
    // PlayingBoard b;
    // b.addToBoard(d.drawCard());
    // b.addToBoard(d.drawCard());
    // b.chargeB();
    // cout << b << endl;
    // Menu m;
    // m.init();
    /* 
    Player p1("Lukas", 30),p2("Sakul", 30);
    TauntCard obr("Obr",3,15);
    BasicCard vojak("Vojak",7,5);
    BattlecryCard silak("Silak",10,5,1);
    BattlecryCard megaSilak("megaSilak",13,6,2);
    TauntCard megaObr("MegaObr",3,20);
    Deck c, d;
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
    p1.print(0);
    p2.print(1);
   
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