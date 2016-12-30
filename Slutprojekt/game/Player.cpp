//
//  Player.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-29.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "Player.hpp"
#include "Sprite.hpp"
#include "Game.hpp"
#include "PlayerShot.hpp"
#include "Graphics.hpp"
#include "Enemy.hpp"
#include "EnemyShot.hpp"


using namespace std;
using namespace engine;

Player::Player(const string texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Point currentPosition, SDL_Point acceleration, int shotSpawnRate, SDL_Rect projectileSrcRect, SDL_Rect shotImpactRect, function<void()> explosionFinishedCallback):
Sprite(texturePath, rectangle, currentPosition, true),
SpaceShuttle(texturePath, bounds, rectangle, currentPosition, acceleration, false, shotSpawnRate, 3, 3, explosionFinishedCallback),projectileSourceRect(projectileSrcRect), shotImpactRect(shotImpactRect){}


void Player::tick(engine::GameEngine *gameEngine){
    if(shouldExplode()){
        explode(gameEngine);
    }
    if(shouldKill()){
        gameEngine->deleteSprite(shared_from_this());
    }
    SDL_Rect bounds = getBounds();
    setCurrentTick(getCurrentTick()+1);
    if(getShooting() && getCurrentTick() >= getShootingDelay()){
        for(int i = 0; i < 2; i++){
            SDL_Point pos = getCurrentPosition();
            pos.y = pos.y + 1;
            pos.x += 1 + (getRect().w - projectileSourceRect.w) * i;
            gameEngine->addSprite(shared_ptr<PlayerShot>(new PlayerShot(getTexturePath(), bounds, projectileSourceRect, shotImpactRect,pos, {0, -(getYAcc()+1)})));
            
        }
        setCurrentTick(0);
    }
    MovableSprite::tick(gameEngine);
}

void Player::handleEvent(SDL_Event &event){
    if(event.type == SDL_KEYUP){
        handleEvent(event,false);
    } else if(event.type == SDL_KEYDOWN){
        handleEvent(event, true);
    }
}

void Player::handleEvent(SDL_Event& event, bool flag){
    switch (event.key.keysym.sym){
        case SDLK_w:
            setAccelerating(flag);
            break;
        case SDLK_a:
            setTurningLeft(flag);
            break;
        case SDLK_s:
            setReversing(flag);
            break;
        case SDLK_d:
            setTurningRight(flag);
            break;
        case SDLK_SPACE:
            setShooting(flag);
            break;
        default:
            return;
    }
}

void Player::didCollideWith(shared_ptr<Sprite> other){
    if(dynamic_pointer_cast<Enemy>(other)){
        setKill(true);
        setShouldExplode(true);
    }else if(dynamic_pointer_cast<Meteor>(other)){
        setKill(true);
        setShouldExplode(true);
    } else if(dynamic_pointer_cast<EnemyShot>(other)){
        if(getLife() == 1){
            setKill(true);
            setShouldExplode(true);
        } else{
            setLife(getLife()-1);
        }
    }
}

void Player::willGoOutOfBounds(SDL_Point at){
    if(isAccelerating() && at.y == -1){
        setAccelerating(false);
    }
    if(isTurningLeft() && at.x == -1){
        setTurningLeft(false);
    }
    if(isReversing() && at.y == 1){
        setReversing(false);
    }
    if(isTurningRight() && at.x == 1){
        setTurningRight(false);
    }
}


