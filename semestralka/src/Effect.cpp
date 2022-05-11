#include "Effect.h"
#include "Player.h"
DrawCardEffect::DrawCardEffect(int s):Effect(s){
    string desc("Draw ");
    if(strength == 1){
        desc.append("a card");    
    } else{
        desc.append(to_string(strength));
        desc.append(" cards");
    }
    effectDesc.push_front(desc);

}
void DrawCardEffect::doEffect(unique_ptr<Player>& src, unique_ptr<Player>& trgt){
    src -> drawCard();
}
void DrawCardEffect::printOstream(ostream& out) const{
    out << "dce;" << strength;
}
void DrawCardEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int DrawCardEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
    }
}
unique_ptr<Effect> DrawCardEffect::copyPtr(){
    return make_unique<DrawCardEffect> (*this);
}
BoardDamageEffect::BoardDamageEffect(int s):Effect(s){
    string desc("Deal ");
    desc.append(to_string(strength));
    desc.append(" damage to");
    effectDesc.push_front(desc);
    desc = "the enemy board";
    effectDesc.push_back(desc);
};
void BoardDamageEffect::doEffect(unique_ptr<Player>& src, unique_ptr<Player>& trgt){
    src -> getBoard().getDamagedOrHealed(-strength);
}
void BoardDamageEffect::printOstream(ostream& out) const{
    out << "bde;" << strength;
}
void BoardDamageEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int BoardDamageEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
        return 0;
    }
}
unique_ptr<Effect> BoardDamageEffect::copyPtr(){
    return make_unique<BoardDamageEffect> (*this);
}
AllDamageEffect::AllDamageEffect(int s):Effect(s){
    string desc("Deal ");
    desc.append(to_string(strength));
    desc.append(" damage to");
    effectDesc.push_front(desc);
    desc = "everybody";
    effectDesc.push_back(desc);
};
void AllDamageEffect::doEffect(unique_ptr<Player>& src, unique_ptr<Player>& trgt){
    src -> getBoard().getDamagedOrHealed(-strength);
    trgt -> getBoard().getDamagedOrHealed(-strength);
    src -> changeHealth(-strength);
    trgt -> changeHealth(-strength);
}
void AllDamageEffect::printOstream(ostream& out) const{
    out << "ade;" << strength;
}
void AllDamageEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int AllDamageEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
    }
}
unique_ptr<Effect> AllDamageEffect::copyPtr(){
    return make_unique<AllDamageEffect> (*this);
}
HealBoardEffect::HealBoardEffect(int s):Effect(s){
    string desc("Add ");
    desc.append(to_string(strength));
    desc.append(" health to");
    effectDesc.push_front(desc);
    desc = "your board";
    effectDesc.push_back(desc);
};
void HealBoardEffect::doEffect(unique_ptr<Player>& src, unique_ptr<Player>& trgt){
    src -> getBoard().getDamagedOrHealed(strength);
}
void HealBoardEffect::printOstream(ostream& out) const{
    out << "hbe;" << strength;
}
void HealBoardEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int HealBoardEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
    }
}
unique_ptr<Effect> HealBoardEffect::copyPtr(){
    return make_unique<HealBoardEffect> (*this);
}
HealHeroEffect::HealHeroEffect(int s):Effect(s){
    string desc("Add ");
    desc.append(to_string(strength));
    desc.append(" health to");
    effectDesc.push_front(desc);
    desc = "your hero";
    effectDesc.push_back(desc);
};
void HealHeroEffect::doEffect(unique_ptr<Player>& src, unique_ptr<Player>& trgt){
    src -> changeHealth(strength);
}
void HealHeroEffect::printOstream(ostream& out) const{
    out << "hhe;" << strength;
}
void HealHeroEffect::printEffect(unsigned int flag){
    if(flag == 1){
        cout << effectDesc.front();
    } else{
        if(effectDesc.size() != 1){
            cout << effectDesc.back();
        }
    }
}
int HealHeroEffect::getLength(int row){
    if(row == 1){
        return effectDesc.front().size();
    } else{
        if(effectDesc.size() != 1){
            return effectDesc.back().size();
        }
        return 0;
    }
}
unique_ptr<Effect> HealHeroEffect::copyPtr(){
    return make_unique<HealHeroEffect> (*this);
}