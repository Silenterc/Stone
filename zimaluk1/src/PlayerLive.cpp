#include "PlayerLive.h"

string PlayerLive::getInput() const{
    string in;
    if(!(cin >> in)){
        clearerr(stdin);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.clear();
        throw invalid_argument("EOF");
    }
    return in;
}
unique_ptr<Player> PlayerLive::clonePtr(){
    return make_unique<PlayerLive>(*this);
}
int PlayerLive::executeTurn(unique_ptr<Player>& trgt){
    string in;
    try{
        in = getInput();
    } catch(...){
        printException("Unknown command.", false);
        return 1;
    }
    if(in == "save"){
        return 2;
    } else if(in == "attack"){
        unsigned long fr;
        try{
            string from = getInput();
            fr = stoul(from);
        } catch(...){
            printException("Wrong from parameter.", false);
            return 1;
        }
        if(fr <= 0 || fr > (boardSize())){
            printException("Wrong from parameter.", true);
            return 1;
        }
        unsigned long to;
        try{
            string trg = getInput();
            to = stoul(trg);
        } catch(...){
            printException("Wrong target parameter.", false);
            return 1;
        }
        if(to > (trgt -> boardSize()) || to < 0){
            printException("Wrong target parameter.", true);
            return 1;
        }
        if(!(attack(fr, to, *trgt))){
            printException("Could not attack.", true);
            return 1;
        }
        if(isDead() || trgt -> isDead()){
            return 0;
        }
        return 1;

    } else if (in == "play"){
        unsigned long index;
        try{
            string ind = getInput();
            index = stoul(ind);
        } catch(...){
            printException("Invalid input.", false);
            return 1;
        }

        if(index <= 0 || index > handSize() || !isCharged() || !(playCard(index, *trgt))){
            printException("Could not play the requested card.", true);
            return 1;
        }
        if(isDead() || trgt -> isDead()){
            return 0;
        }
        return 1;
    } else if (in == "end"){
        return 0;
    }  else if(in == "exit"){
        return -1;
    }else{
        printException("Unknown command.", true);
        return 1;
    }  
    return 0;           
    
}
void PlayerLive::printConfirmation() const{
    cout << "\033[H\033[2J" << flush;
    printLines(5);
    printSpaces((getTermWidth() - 22)/2);
    cout << "type anything to switch" << endl;
    try{
        getInput();
    } catch(...){
        clearerr(stdin);
        cin.clear();
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void PlayerLive::print(unsigned int flag) const{
    if(flag){
        board.print();
        cout << endl;
        printDashes();
        cout << endl;
        hand.print();
        cout << endl;
        printInfo(flag);
    } else{
        printInfo(flag);
        hand.printCensored();
        cout << endl;
        printDashes();
        cout << endl;
        board.print();
        cout << endl;
        printDashes();
        cout << endl;
    }    
}
