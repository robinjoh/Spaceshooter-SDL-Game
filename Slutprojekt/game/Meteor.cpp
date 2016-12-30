//
//  Meteor.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-28.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "Meteor.hpp"
#include "Game.hpp"
#include "PlayerShot.hpp"
#include "Enemy.hpp"

using namespace std;

Meteor::Meteor(const string texturePath, SDL_Rect bounds, SDL_Rect rectangle,SDL_Point currentPosition, SDL_Point acceleration,int rotationSpeed, function<void(shared_ptr<Entity>)> onKilledCallback):Sprite(texturePath, rectangle, currentPosition, true),Entity(3, 10),
RotatingSprite(texturePath, rectangle, currentPosition, rotationSpeed),MovableSprite(texturePath, bounds, rectangle, currentPosition, acceleration), onKilledCallback(onKilledCallback){
    if(acceleration.x > 0){
        setTurningLeft(true);
    } else if(acceleration.x < 0) {
        setTurningRight(true);
    }
    setReversing(true);
}

void Meteor::tick(engine::GameEngine* gameEngine){
    RotatingSprite::tick(gameEngine);
    MovableSprite::tick(gameEngine);
    if(shouldExplode()){
        explode(gameEngine);
    }
    if(shouldKill()){
        gameEngine->deleteSprite(shared_from_this());
    }
}

void Meteor::didGoOutOfBounds(SDL_Point at){
    setKill(true);
}

void Meteor::didCollideWith(shared_ptr<Sprite> other){
    if(dynamic_pointer_cast<Meteor>(other)){
        setXacc(-(getXAcc()));
        setYacc(-(getYAcc()));
    } else if(dynamic_pointer_cast<PlayerShot>(other)){
        if(getLife() == 1){
            onKilledCallback(dynamic_pointer_cast<Meteor>(shared_from_this()));
            setKill(true);
            setShouldExplode(true);
        } else {
            setLife(getLife()-1);
        }
    } else if(dynamic_pointer_cast<Enemy>(other)){
        if(getXAcc() > 0 && getYAcc() > 0){
            setXacc(-(getXAcc()));
        }else {
            setXacc(-(getXAcc()));
            setYacc(-(getYAcc()));
        }
    }
}
