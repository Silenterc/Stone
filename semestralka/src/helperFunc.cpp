#include "helperFunc.h"
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
    tmp << "l";
   // tmp << put_time(&time,"%d-%m-%Y,%H-%M-%S");
    string ret = tmp.str();
    return ret;
}