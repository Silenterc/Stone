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
        printSpaces((getTermWidth()/2) - MENUMIDDLE);
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
            case -1: return;
            case 0: cout <<"Invalid input, please try again." << endl;
                    sleep(2);
                    break;
            case 1: {
                        Game g;
                        try{
                            g.initStart(true);
                            g.play();
                        } catch(...){
                            cout << "Could not load Game/damaged files" << endl;
                            sleep(2);
                            break;
                        }
                        break;
            }
            case 2: {
                        Game ai;
                        try{
                            ai.initStart(false);
                            ai.play();
                        } catch(...){
                            cout << "Could not load Game/damaged files" << endl;
                            sleep(2);
                            break;
                        }
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
    if(!(cin >> in)){
        clearerr(stdin);
        cin.clear();
        return 0;
    }
    if(in=="exit"){
        return -1;
    }
    int num;
    try{
        num = stoi(in);
    } catch(...){
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return 0;
    }
    if(num > 4 || num < 1){
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
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
    sort(svs.begin(),svs.end(), 
    [](const filesystem::directory_entry & a, const filesystem::directory_entry & b) -> bool{ 
        return a.path().string() > b.path().string(); 
    }
    );
    return svs;
}
void Menu::fileMenu() const{
    vector<filesystem::directory_entry> saves = loadSaves();
    while(true){
        printSaves(saves);
        unsigned long in = saveInput();
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
            Game g;
            try{
                g.loadGame(loaded, gameType);
            } catch(...){
                cout << "Save File in wrong format" << endl;
                sleep(3);
                continue;
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
unsigned long Menu::saveInput() const{
    cout << endl;
    cout << "Which Save File would you like to choose?" << endl;
    int i = 0;
    if(!(cin >> i) || i < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return 0;
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return (unsigned long)i;
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
