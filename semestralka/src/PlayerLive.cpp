#include "PlayerLive.h"

string PlayerLive::getInput(){
    string in;
    cin >> in;
    return in;
}
unique_ptr<Player> PlayerLive::clonePtr(){
    return make_unique<PlayerLive>(*this);
}
int PlayerLive::executeTurn(unique_ptr<Player>& trgt){
    string in = getInput();
    if(in == "save"){
        return 2;
    } else if(in == "attack"){
        string from = getInput();
        int fr;
        try{
            fr = stoi(from);
        } catch(...){
            cout << "Wrong from parameter" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            sleep(5);
            return 1;
        }
        if(fr <= 0 || fr > (boardSize())){
            cout << "Wrong from parameter" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            sleep(5);
            return 1;
        }
        string trg = getInput();
        int to;
        try{
            to = stoi(trg);
        } catch(...){
            cout << "Wrong target parameter" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            sleep(5);
            return 1;
        }
        if(to > trgt -> boardSize() || to < 0){
            cout << "Wrong target parameter" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            sleep(5);
            return 1;
        }
        if(!(attack(fr, to, *trgt))){
            cout << "Could not attack." << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            sleep(5);
            return 1;
        }
        if(isDead() || trgt -> isDead()){
            return 0;
        }
        return 1;

    } else if (in == "play"){
        string ind = getInput();
        int index;

        try{
            index = stoi(ind);
        } catch(...){
            cout << "Invalid input." << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            sleep(5);
            return 1;
        }

        if(index <= 0 || index > handSize() || !isCharged() || !(playCard(index, *trgt))){
            cout << "Could not play the requested card." << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            sleep(5);
            return 1;
        }
        uncharge();
        if(isDead() || trgt -> isDead()){
            return 0;
        }
        return 1;
    } else if (in == "end"){
        return 0;
    } else{
        cout << "Unknown command." << endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        sleep(5);
        return 1;
    }  
    return 0;           
    
}