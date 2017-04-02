#include "Shade.h"
#include "Halfling.h"
#include "Merchant.h"
#include <string>

Shade::Shade(){
    HP = 125;
    Atk = 25;
    Def = 25;
    MaxHP = 125;
    playerRace = "Shade";
}

void Shade::attackIt(std::shared_ptr<Halfling> e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/(100+d)) * getAttack());
        update_message("PC deals ");
        update_message(std::to_string(damage));
        update_message(" damage to Halfling");
        update_message("(");
        update_message(std::to_string(e->getHP()));
        update_message("/");
        update_message(std::to_string(e->getMaxHP()));
        update_message(").");
        e->updateDamage(damage);
    }else{
        update_message("PC misses attack to Halfing. ");
    }
    
    check_dead(e);
}

void Shade::attackIt(std::shared_ptr<Merchant> e){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Merchant. ");
    update_message("(");
    update_message(std::to_string(e->getHP()));
    update_message("/");
    update_message(std::to_string(e->getMaxHP()));
    update_message(")");
    e->updateDamage(damage);
    e->setNeutral();
    check_dead(e);
}
Shade::~Shade(){}
