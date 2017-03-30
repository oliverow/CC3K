#include "Goblin.h"
#include "Halfling.h"
#include "Merchant.h"
using namespace std;

Goblin::Goblin(){
    HP = 110;
    Atk = 15;
    Def = 20;
    MaxHP = 110;
    steal = true;
}

void Goblin::attackIt(std::shared_ptr<Halfling> e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
    }
}

void Goblin::attackIt(std::shared_ptr<Merchant> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    e->setNeutral();
}
Goblin::~Goblin(){}
