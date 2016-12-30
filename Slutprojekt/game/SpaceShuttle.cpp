//
//  SpaceShip.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-05.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "SpaceShuttle.hpp"
using namespace std;
using namespace engine;

SpaceShuttle::SpaceShuttle(const string texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Point currentPosition, SDL_Point acceleration, bool shooting, int shootingDelay,int killValue, int durability, function<void()> explosionFinishedCallback): Sprite(texturePath, rectangle, currentPosition, true),MovableSprite(texturePath, bounds, rectangle, currentPosition, acceleration), Entity(durability, killValue), Explodable(explosionFinishedCallback),shooting(shooting), shootingDelay(shootingDelay)                                                                                                                                                                                    {}

int SpaceShuttle::getShootingDelay() const {
    return shootingDelay;
}

bool SpaceShuttle::getShooting() const {
    return shooting;
}


void SpaceShuttle::setShooting(bool shoot){
    shooting = shoot;
}
