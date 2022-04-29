#include "Hand.h"
#include <sys/ioctl.h> 
#include <unistd.h> 
#include <iostream>
#include <queue>
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
int Hand::getNamesLengths() const{
    size_t sum = 0;
    for(const auto& i : cards){
        sum += i -> getNameLength();
    }
    return (int)sum;
}
int Hand::prevPrinted(unsigned int row, size_t column, int prevDiff) const{
    switch(row){
        case(1):{
            return cards[column - 1] -> getNameLength();
            return 0;
        }
        case(2):{
            int spc = cards[column - 1] -> getTypeLength() - cards[column - 1] -> getNameLength();
            spc += prevDiff; //still need to account for the previous difference
            return spc;
        }
        case(3):{
            int spc = cards[column - 1] -> getDamageLength() - cards[column - 1] -> getTypeLength();
            spc += prevDiff;  
            return spc;
        }
        case(4):{
            int spc = cards[column - 1] -> getHealthLength() - cards[column - 1] -> getDamageLength();
            spc += prevDiff; 
            return spc;
        }
        default : return 0;
    }
}
void Hand::printSpaces(int spaces) const{
    for(int i = 0; i < spaces; i++){
        cout <<" ";
    }
}
void Hand::print() const{
    int SPACESCONSTANT = getTermSize()/10;
    int middleSpaces = (getTermSize() - 2 * SPACESCONSTANT)/MAXHANDSIZE;
    int spaces = 0;
    int prevDiff = 0;
    queue<int> prevDifferences;
    for(int i = 0; i < size - 1; i++){
        prevDifferences.push(0);
    }
    for(unsigned int l = 1; l < 5; l++){
        prevDiff = 0;
        for(size_t i = 0; i < size; i++){
            if(i == 0){
                spaces = SPACESCONSTANT;
            } else{
                prevDiff = prevPrinted(l, i, prevDifferences.front());
                prevDifferences.pop();
                prevDifferences.push(prevDiff);
                spaces = middleSpaces - prevDiff; 
            }
            printSpaces(spaces);
            cards[i] -> printCard(l);
        }
        cout << endl;
    } 
    
    
    
    // for(const auto& i: cards){
    //     i -> printCard();
    // }
}