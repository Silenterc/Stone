#include "Menu.h"
using namespace std;
vector<string> Menu::MENU = {{" I      I     I-------     I      I     I      I    "},
                             {" I \\  / I     I            I\\     I     I      I    "},
                             {" I  \\/  I     I            I \\    I     I      I    "},
                             {" I      I     I-------     I  \\   I     I      I    "},   
                             {" I      I     I            I   \\  I     I      I    "},
                             {" I      I     I            I    \\ I     \\      /     "},
                             {" I      I     I-------     I     \\I      \\____/      "},

};
filesystem::path Menu::savesPath = {"assets/saves"};
void Menu::printMENU() const{
    for(const auto& row : MENU){
        printSpaces((getTermSize()/2) - MENUMIDDLE);
        for(const auto& col : row){
            cout << col;
        }
        cout << endl;
    }
}
void Menu::init(){
    while(true){
        cout << "\033[H\033[2J" << flush;   
        printOptions();
        switch(getMenuInput()){
            case 0: cout <<"Invalid input, please try again." << endl;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    sleep(2);
                    break;
            case 1: {
                        GamePvP g;
                        g.play();
                        break;
            }
            case 2: {
                        GamePvP ai;
                        ai.play();
                        break;                
            }
            case 3: {
                        try{
                            fileMenu();
                            break;
                        } catch(...){
                            cout << "Could not manipulate with files." << endl;
                            break;
                        }
            }
            case 4: printInstructions();
                    cout <<"Type in anything to return to the Menu." << endl;
                    string s ;
                    cin >> s;
                    break;
        }
   
   
    }

}
void Menu::printInstructions() const{
    ifstream instructions = loadFile("assets/instructions");
    cout << "\033[H\033[2J" << flush; 
    cout << instructions.rdbuf() << endl;
}
void Menu::printOptions() const{
    printMENU();
    printLines(6);
    cout <<"To play a PvP Game, type in 1" << endl;
    printLines(6);
    cout <<"To play a Game against an AI, type in 2" << endl;
    printLines(6);
    cout <<"To load a Game, type in 3" << endl;
    printLines(6);
    cout <<"To view instructions, type in 4" << endl;
}
int Menu::getMenuInput() const{
    string in;
    cin >> in;
    int num;
    try{
        num = stoi(in);
    } catch(...){
        return 0;
    }
    if(num > 4 || num < 1){
        return 0;
    }
    return num;
}
vector<filesystem::directory_entry> Menu::loadSaves() const{
    vector<filesystem::directory_entry> svs;
    for(auto& dirIt : filesystem::directory_iterator{savesPath}){
        if(!(dirIt.path().filename().string()[0] == '.')){
            svs.push_back(dirIt);
        }
    }
    return svs;
}
void Menu::fileMenu() const{
    vector<filesystem::directory_entry> saves = loadSaves();
    while(true){
        printSaves(saves);
        int in = saveInput();
        if(in == 0 || in > saves.size()){
            cout << "Wrong input." << endl;
            sleep(3);
            continue;
        } else{
            ifstream loaded = loadFile(saves[in - 1].path().string());
            if(loaded.fail()){
                cout << "Could not open Save File." << endl;
                sleep(3);
                continue;
            }
            bool gameType;
            try{
                gameType = extractGameType(loaded);
            } catch(...){
                cout << "Save File in wrong format" << endl;
                sleep(3);
                continue;
            }
            if(gameType){
                cout << "Load pvp game" << endl;
            } else{
                cout << "Load ai game" << endl;
             }
            break;
        }

    }
    
}
void Menu::printSaves(vector<filesystem::directory_entry> svs) const{
    cout << "\033[H\033[2J" << flush;
    int i = 1;
    for(const filesystem::directory_entry& dirEn : svs){
        printLines(30);
        cout << i << ", " << dirEn.path().filename() << endl;
        i++;
    } 
}
int Menu::saveInput() const{
    cout << endl;
    cout << "Which Save File would you like to choose?" << endl;
    int i = 0;
    if(!(cin >> i)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return 0;
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return i;
}
bool Menu::extractGameType(ifstream& in) const{
    string type;
    getline(in, type);
    if(type == "PvP"){
        return true;
    } else if(type == "AI"){
        return false;
    } else{
        throw invalid_argument("Not valid Game Type");
    }
}
