//
//  EnemyShot.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-07.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "EnemyShot.hpp"
#include "Enemy.hpp"
#include "ShotImpact.hpp"
#include "Player.hpp"
#include "Meteor.hpp"

using namespace std;
using namespace engine;

EnemyShot::EnemyShot(const std::string texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Rect impactRect,SDL_Point currentPosition, SDL_Point acceleration):
Sprite(texturePath, rectangle, currentPosition, true),
Entity(1, 0),
MovableSprite(texturePath, bounds, rectangle,currentPosition,acceleration), impactRect(impactRect), spawnImpact(false) {
    setReversing(true);
}

void EnemyShot::tick(engine::GameEngine* engine){
    engine::MovableSprite::tick(engine);
    if(shouldKill()){
        if(spawnImpact){
            engine->addSprite(new ShotImpact(getTexturePath(), impactRect, {getCurrentPosition().x + getRect().w / 2- impactRect.w / 2, getCurrentPosition().y}));
        }
        engine->deleteSprite(shared_from_this());
    }
}

void EnemyShot::didGoOutOfBounds(SDL_Point at){
    setKill(true);
}

void EnemyShot::didCollideWith(shared_ptr<Sprite> other){
    if(dynamic_pointer_cast<Player>(other) ||dynamic_pointer_cast<Meteor>(other) || dynamic_pointer_cast<Enemy>(other)){
        spawnImpact = true;
        setKill(true);
    }
}
