//
//  Subject.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#include "Subject.h"
#include "Observer.h"
#include "Info.h"

Subject::Subject(){
    
}


void Subject::attatch(Observer *o){
    observers.emplace_back(o);
}

void Subject::detach(Observer *o){
    int pos =0;
    for(int i =0;i< observers.size();i++){
        if(observers[i] == o){
            break;
        }
        pos++;
    }
    
    observers.erase(observers.begin()+pos);
}

void Subject::notifyObservers(SubscriptionType t){
    for(int i =0; i < observers.size();i++){
        observers[i]->notify(*this);//not sure
    }
}





