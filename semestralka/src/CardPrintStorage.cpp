#include "CardPrintStorage.h"
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
shared_ptr<Card> CardPrintStorage::viewCard(int cardNO) const{
    return cards[cardNO - 1];
}

//This function will calculate the difference between the previous words printed 
//so I can then balance out the amount of spaces to print for each attribute
//The first card printed actually has a set amount of spaces(SPACECONSTANT)
int CardPrintStorage::prevPrinted(unsigned int row, size_t column, int prevDiff) const{
    switch(row){                                                      
        case(1):{ //When printing the first row (card names) I only want to decrement the amount of spaces by the length of the name                                                   
            return cards[column - 1] -> getNameLength();             
        }
        case(2):{ //second row(card Type).
            //difference between the length of the previous card's name and type strings.
            //f.e.:    Giant            Elf
            //         Battlecry        => and I am calculating the amount of spaces needed here(4 + prevDiff)   
            int spc = cards[column - 1] -> getTypeLength() - cards[column - 1] -> getNameLength(); 
            spc += prevDiff; //still need to account for the previous previous difference as well
            return spc;
        }
        case(3):{ //third row(card Damage)
            int spc = cards[column - 1] -> getDamageLength() - cards[column - 1] -> getTypeLength();
            spc += prevDiff;  
            return spc;
        }
        case(4):{ //fourth row(card Health)
            int spc = cards[column - 1] -> getHealthLength() - cards[column - 1] -> getDamageLength();
            spc += prevDiff; 
            return spc;
        }
        case(5):{
            int spc = 0;
            int potentialBatID = cards[column - 1] -> getBattlecry();
            if(!potentialBatID){
                spc -= cards[column - 1] -> getHealthLength();
            } else{
                spc = cards[column - 1] -> getBattlecryLength(potentialBatID,1) - cards[column - 1] -> getHealthLength();
            }
            spc += prevDiff;
            return spc;
        }
        case(6):{
            int spc = 0;
            int potentialBatID = cards[column - 1] -> getBattlecry();
            if(potentialBatID){
                spc = cards[column - 1] -> getBattlecryLength(potentialBatID,2) - cards[column - 1] -> getBattlecryLength(potentialBatID,1);
            }
            spc += prevDiff;
            return spc;
        }
        default : return 0;
    }
}
void printSpaces(int spaces){
    for(int i = 0; i < spaces; i++){
        cout <<" ";
    }
}
void CardPrintStorage::print() const{
    int SPACESCONSTANT = getTermSize()/10; //By how many spaces to indent the first card
    int middleSpaces = (getTermSize() - 2 * SPACESCONSTANT)/maxStorageSize;//The base amount of spaces between cards
    int spaces = 0;
    int prevDiff = 0;
    queue<int> prevDifferences; //I need to keep track of the previous differences in spaces, and this queue does it well
    if(size > 0){
        for(int i = 0; i < size - 1; i++){ //For the first row to be printed (card Names), there obviously are not any previous differences
            prevDifferences.push(0);
        }
    }
    for(unsigned int l = 1; l < 7; l++){
        for(size_t i = 0; i < size; i++){
            if(i == 0){ //first card gets indented based on the constant I have set
                spaces = SPACESCONSTANT;
            } else{
                prevDiff = prevPrinted(l, i, prevDifferences.front());
                prevDifferences.pop();
                prevDifferences.push(prevDiff); 
                spaces = middleSpaces - prevDiff; 
            }
            printSpaces(spaces);
            cards[i] -> print(l);
        }
        cout << endl;
    } 
}
void CardPrintStorage::printStars(int stars) const{
    for(int i = 0; i < stars; i++){
        cout <<'*';
    }
}
void CardPrintStorage::printCensored() const{
    int SPACESCONSTANT = getTermSize()/10;
    int middleSpaces = (getTermSize() - 2 * SPACESCONSTANT)/maxStorageSize;
    int spaces = 0;
    for(unsigned int l = 1; l < 5; l++){
        for(size_t i = 0; i < size; i++){
            if(i == 0){ 
                spaces = SPACESCONSTANT;
            } else{
                spaces = middleSpaces - 5; 
            }
            printSpaces(spaces);
            printStars(5);
        }
        cout << endl;
    } 
}