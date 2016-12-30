//
//  Enemy.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "Enemy.hpp"
#include "PlayerShot.hpp"
#include "EnemyShot.hpp"

using namespace std;
using namespace engine;

Enemy::Enemy(const string texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Rect shotRect, SDL_Rect shotImpactRect,SDL_Point currentPosition, SDL_Point acceleration, bool shooting, int shootingDelay, function<void(shared_ptr<Entity>)> onCollideWithPlayerShotCallback):Sprite(texturePath, rectangle, currentPosition, true), SpaceShuttle(texturePath, bounds, rectangle, currentPosition, acceleration,shooting, shootingDelay, 5, 1),collideWithPlayerProjectileCallback(onCollideWithPlayerShotCallback), shotRect(shotRect), shotImpactRect(shotImpactRect){
    setReversing(true);
}

void Enemy::tick(engine::GameEngine* gameEngine){
    setShooting(rand() % 100 < 25);
    if(getShooting() && getCurrentTick() >= getShootingDelay()) {
        gameEngine->addSprite(shared_ptr<EnemyShot>(new EnemyShot(getTexturePath(), getBounds(),shotRect,shotImpactRect,{getCurrentPosition().x + getRect().w / 2 - shotRect.w / 2, getCurrentPosition().y + getRect().h + 2},{0, +(getYAcc()+shotSpeed)})));
        setCurrentTick(0);
    }
    MovableSprite::tick(gameEngine);
    if(shouldExplode()){
        explode(gameEngine);
    }
    if(shouldKill()){
        gameEngine->deleteSprite(shared_from_this());
    }
    setCurrentTick(getCurrentTick()+1);
}

void Enemy::didGoOutOfBounds(SDL_Point at){
    setKill(true);
}


void Enemy::didCollideWith(shared_ptr<Sprite> other){
    if(shared_ptr<Enemy> ene = dynamic_pointer_cast<Enemy>(other)){
        if(other->getCurrentPosition().y < getCurrentPosition().y){
            setYacc(ene->getYAcc() + 1);
        }
    } else if(dynamic_pointer_cast<Player>(other)){
        setKill(true);
        setShouldExplode(true);
    }else if(dynamic_pointer_cast<Meteor>(other)){
        setKill(true);
        setShouldExplode(true);
    } else if(dynamic_pointer_cast<PlayerShot>(other)){
        collideWithPlayerProjectileCallback(dynamic_pointer_cast<Enemy>(shared_from_this()));
        setKill(true);
        setShouldExplode(true);
    }
}

