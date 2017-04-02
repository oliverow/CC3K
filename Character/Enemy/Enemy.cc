#include "Enemy.h"
#include "Info.h"
#include "Player.h"
#include "Drow.h"
#include "Vampire.h"
#include "Shade.h"
#include "Goblin.h"
#include "Troll.h"
using namespace std;

void Enemy::updateDamage(double damage){
    HP = HP - damage;
    if(HP <= 0){
        Dead = true;
        notifyObservers(SubscriptionType::displayOnly);
    }
}

void Enemy::notify(Subject &notifier){
//    Info f = getInfo();
    int r = currentRow;
    int c = currentCol;
    if(isneutral){
        move();
    }else if((*gO)[r-1][c]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r-1][c]);
        attack(p);
    }else if((*gO)[r+1][c]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r+1][c]);
        attack(p);
    }else if((*gO)[r-1][c+1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r-1][c+1]);
        attack(p);
    }else if((*gO)[r-1][c-1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r-1][c-1]);
        attack(p);
    }else if((*gO)[r+1][c+1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r+1][c+1]);
        attack(p);
    }else if((*gO)[r+1][c-1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r+1][c-1]);
        attack(p);
    }else if((*gO)[r][c+1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r][c+1]);
        attack(p);
    }else if((*gO)[r][c-1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r][c-1]);
        attack(p);
    }else if(!stationary){
        move();
    }
}

void Enemy::move(){  //if enemy is stuck, you fucked up!
    int r = currentRow;
    int c = currentCol;
    int direction;
    while(true){
        direction = rand()%8+1;
        if(direction == 1 && (*gO)[r-1][c]->getObsType() == ObstacleType::BlockNone){ // north
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r-1][c];
            (*gO)[r-1][c] = g;
            currentRow -= 1;
            break;
        } else if(direction == 2 && (*gO)[r+1][c]->getObsType() == ObstacleType::BlockNone){ //south
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r+1][c];
            (*gO)[r+1][c] = g;
            currentRow += 1;
            break;
        } else if(direction == 3 && (*gO)[r-1][c+1]->getObsType() == ObstacleType::BlockNone){ //northeast
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r-1][c+1];
            (*gO)[r-1][c+1] = g;
            currentRow -= 1;
            currentCol += 1;
            break;
        } else if(direction == 4 && (*gO)[r-1][c-1]->getObsType() == ObstacleType::BlockNone){ //northwest
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r-1][c-1];
            (*gO)[r-1][c-1] = g;
            currentRow -= 1;
            currentCol -= 1;
            break;
        } else if(direction == 5 && (*gO)[r+1][c+1]->getObsType() == ObstacleType::BlockNone){//southeast
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r+1][c+1];
            (*gO)[r+1][c+1] = g;
            currentRow += 1;
            currentCol += 1;
            break;
        } else if(direction == 6 && (*gO)[r+1][c-1]->getObsType() == ObstacleType::BlockNone){//southwest
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r+1][c-1];
            (*gO)[r+1][c-1] = g;
            currentRow += 1;
            currentCol -= 1;
            break;
        } else if(direction == 7 && (*gO)[r][c+1]->getObsType() == ObstacleType::BlockNone){//east
            shared_ptr<GridObjects>g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r][c+1];
            (*gO)[r][c+1] = g;
            currentCol += 1;
            break;
        } else if(direction == 8 && (*gO)[r][c-1]->getObsType() == ObstacleType::BlockNone){//west
            shared_ptr<GridObjects>g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r][c-1];
            (*gO)[r][c-1] = g;
            currentCol -= 1;
            break;
        }
    }
    this->notifyObservers(SubscriptionType::displayOnly);
    previousCol = currentCol;
    previousRow = currentRow;
}

void Enemy::attack(shared_ptr<Player> pc){
    pc->update_enemy(this);
    if(dynamic_pointer_cast<Drow>(pc)){
        attack(dynamic_pointer_cast<Drow>(pc));
    }else if(dynamic_pointer_cast<Goblin>(pc)){
        attack(dynamic_pointer_cast<Goblin>(pc));
    }
    else if(dynamic_pointer_cast<Drow>(pc)){
        attack(dynamic_pointer_cast<Drow>(pc));
    }
    else if(dynamic_pointer_cast<Shade>(pc)){
        attack(dynamic_pointer_cast<Shade>(pc));
    }
    else if(dynamic_pointer_cast<Troll>(pc)){
        attack(dynamic_pointer_cast<Troll>(pc));
    }else if(dynamic_pointer_cast<Vampire>(pc)){
        attack(dynamic_pointer_cast<Vampire>(pc));
    }
}
void Enemy::attack(std::shared_ptr<Drow> pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    int miss = rand()%2+1;
    if (miss == 1){
        pc->getDamage(damage);
    }

}
void Enemy::attack(std::shared_ptr<Goblin> pc){
    double d = pc->getDefence();
    double damage = ceil((100/(100+d)) * this->Atk);
    int miss = rand()%2+1;
    if (miss == 1){
        pc->getDamage(damage);
    }

}
void Enemy::attack(std::shared_ptr<Shade> pc){
    double d = pc->getDefence();
    double damage = ceil((100/(100+d)) * this->Atk);
    int miss = rand()%2+1;
    if (miss == 1){
        pc->getDamage(damage);
    }

}
void Enemy::attack(std::shared_ptr<Troll> pc){
    double d = pc->getDefence();
    double damage = ceil((100/(100+d)) * this->Atk);
    int miss = rand()%2+1;
    if (miss == 1){
        pc->getDamage(damage);
    }

}
void Enemy::attack(std::shared_ptr<Vampire> pc){
    double d = pc->getDefence();
    double damage = ceil((100/(100+d)) * this->Atk);
    int miss = rand()%2+1;
    if (miss == 1){
        pc->getDamage(damage);
    }

}
void Enemy::setNeutral(){
    isneutral = false;
}

bool Enemy::isDead(){
    return Dead;
}

int Enemy::dropgold(){
    return gold;
}

GridObjectType Enemy::getObjType(){
    return GridObjectType::Enemy;
}

SubscriptionType Enemy::getSubType() const{
    return SubscriptionType::All;
}
