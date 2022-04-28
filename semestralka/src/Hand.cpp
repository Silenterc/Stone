#include "Hand.h"
#include <sys/ioctl.h> 
#include <unistd.h> 
#include <iostream>
using namespace std;
unsigned int getTermSize(){
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return (unsigned int)size.ws_col;
}
pair<string, bool> Hand::drawCard(Deck& deck){
    if(size >= MAXHANDSIZE){
        return(make_pair<string,bool>(deck.drawCard() -> getName(), false));
    }
    shared_ptr<Card> newOne = deck.drawCard();
    pair<string,bool> toBeRet = make_pair<string,bool>(newOne -> getName(), true);
    cards.push_back(newOne);
    size++;
    return toBeRet;
}
shared_ptr<Card> Hand::getCard(int cardNO) const{
    return cards[cardNO - 1];
}
shared_ptr<Card> Hand::playCard(int cardNO){
    shared_ptr<Card> toBeRet = cards[cardNO - 1];
    cards.erase(cards.begin() + (cardNO - 1));
    return toBeRet;
}
size_t Hand::getNamesLengths() const{
    size_t sum = 0;
    for(const auto& i : cards){
        sum += i -> getNameLength();
    }
    return sum;
}
void Hand::print() const{
    int namesLengths =(int)getNamesLengths();
    int spaces = (getTermSize() - namesLengths)/(int)size;
    for(unsigned int l = 1; l < 5; l++){
    for(size_t i = 0; i < size; i++){
      cards[i] -> printCard(l, spaces);
    }
    cout << endl;
  }  
    
    
    
    for(const auto& i: cards){
        i -> printCard();
    }
}