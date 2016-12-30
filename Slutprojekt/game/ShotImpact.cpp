//
//  ShotImpact.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-10.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "ShotImpact.hpp"
#include "GameEngine.hpp"

class GameEngine;

ShotImpact::ShotImpact(const std::string texturePath, SDL_Rect rectangle, SDL_Point currentPosition): StaticSprite(texturePath, rectangle, currentPosition){}

void ShotImpact::tick(engine::GameEngine* gameEngine){
    setCurrentTick(getCurrentTick()+1);
    if(getCurrentTick() >= lifeTime){
        gameEngine->deleteSprite(shared_from_this());
    }
}
