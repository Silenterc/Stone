#include "helperFunc.h"
list<string> battlecryIDtoString(int ID){
    switch(ID){
        case 1: return list<string>{"Draw a card and add","1 health to your hero"};
        case 2: return list<string>{"Deal 2 damage to","the enemy board"};
        case 3: return list<string>{"Deal 3 damage to","everybody"};
        case 4: return list<string>{"Add 2 health to","your board and hero"};
        case 5: return list<string>{"Deal 2 damage to","the enemy hero"};
        default: throw invalid_argument("INVALID BATTLECRYID");
    }
}
unsigned int getTermSize(){
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return (unsigned int)size.ws_col;
}
unsigned int getTermWidth(){
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return (unsigned int)size.ws_row;
}
void printSpaces(int spaces){
    for(int i = 0; i < spaces; i++){
        cout <<" ";
    }
}
void printLines(int divisor){
    for(unsigned int i = 0; i < getTermWidth()/divisor; i++){
        cout << endl;
    }
}
ifstream loadFile(const string& path){
    ifstream in;
    in.open(path);
    if(in.fail()){
        throw invalid_argument("COULD NOT OPEN FILE");
    }
    return in;
}
string getLocalTime(){
    auto timeVar = time(nullptr);
    auto time = *localtime(&timeVar);
    stringstream tmp;
    tmp << put_time(&time,"%d-%m-%Y,%H-%M-%S");
    string ret = tmp.str();
    return ret;
}