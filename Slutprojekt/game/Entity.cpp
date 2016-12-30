//
//  Entity.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-07.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(int life, int killValue): life(life), killValue(killValue), killThis(false){}

Entity::~Entity(){};

int Entity::getKillValue() const {
    return killValue;
}

void Entity::setKill(bool k){
    killThis = k;
}

bool Entity::shouldKill() const{
    return killThis;
}

void Entity::setLife(int newLife){
    life = newLife;
}
int Entity::getLife() const {
    return life;
}
