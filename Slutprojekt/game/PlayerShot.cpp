//
//  PlayerShot.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-28.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "PlayerShot.hpp"
#include "AnimatedSprite.hpp"
#include "ShotImpact.hpp"
#include "Enemy.hpp"
using namespace std;
using namespace engine;

PlayerShot::PlayerShot(const std::string texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Rect impactSrc, SDL_Point currentPosition, SDL_Point acceleration):
Entity(1),
Sprite(texturePath, rectangle, currentPosition, true),
MovableSprite(texturePath, bounds, rectangle,currentPosition,acceleration), spawnImpact(false),impactSrcRect(impactSrc){
    setReversing(true);
}

void PlayerShot::tick(engine::GameEngine* engine){
    engine::MovableSprite::tick(engine);
    if(shouldKill()){
        if(spawnImpact){
            engine->addSprite(shared_ptr<ShotImpact>(new ShotImpact(getTexturePath(), impactSrcRect,{getCurrentPosition().x - impactSrcRect.w /  2, getCurrentPosition().y})));
        }
        engine->deleteSprite(shared_from_this());
    }
}

void PlayerShot::didCollideWith(shared_ptr<Sprite> other){
    if(shared_ptr<Enemy> ene = dynamic_pointer_cast<Enemy>(other)){
        spawnImpact = true;
        setKill(true);
    } else if(shared_ptr<Meteor> ene = dynamic_pointer_cast<Meteor>(other)){
        spawnImpact = true;
        setKill(true);
    }
}

void PlayerShot::didGoOutOfBounds(SDL_Point at){
    setKill(true);
}
