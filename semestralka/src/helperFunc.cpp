#include "helperFunc.h"
unsigned int getTermWidth(){
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return (unsigned int)size.ws_col;
}
unsigned int getTermHeight(){
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
    for(unsigned int i = 0; i < getTermHeight()/divisor; i++){
        cout << endl;
    }
}
void printStars(int stars){
    for(int i = 0; i < stars; i++){
        cout <<'*';
    }
}
void printException(const string& ex, bool shouldIgnore){
    if(shouldIgnore){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << ex << endl;
    clearerr(stdin);
    cin.clear();
    sleep(3);
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
