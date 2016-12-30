//
//  MovableSprite.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "MovableSprite.hpp"
#include <string>

using namespace std;

namespace engine {

    SDL_Point MovableSprite::goingOutOfBounds(){
        SDL_Point goingOutAt = {0,0};
        SDL_Rect currentPosRect = {getCurrentPosition().x, getCurrentPosition().y , getRect().w, getRect().h};
        if(reversing && bounds.h < currentPosRect.y + currentPosRect.h + acceleration.y){
            goingOutAt.y = 1;
        }
        if(accelerating && bounds.y > currentPosRect.y - acceleration.y){
            goingOutAt.y = -1;
        }
        if(turningRight && bounds.w < currentPosRect.x + currentPosRect.w + acceleration.x){
            goingOutAt.x = 1;
        }
        if(turningLeft && bounds.x > currentPosRect.x - acceleration.x){
            goingOutAt.x = -1;
        }
        return goingOutAt;
    }
    
    SDL_Point MovableSprite::isOutOfBounds(){
        SDL_Point didGoOut = {0,0};
        SDL_Rect currentPosRect = {getCurrentPosition().x, getCurrentPosition().y , getRect().w, getRect().h};
        if(bounds.w < currentPosRect.x + currentPosRect.w && bounds.w <= currentPosRect.x + currentPosRect.w){
            didGoOut.x = 1;
        } else if(bounds.x > currentPosRect.x + currentPosRect.w){
            didGoOut.x = -1;
        } else if(bounds.y > currentPosRect.y + currentPosRect.h){
            didGoOut.y = 1;
        } else if(bounds.h < currentPosRect.y && bounds.h <= currentPosRect.y + currentPosRect.h){
            didGoOut.y = -1;
        }
        return didGoOut;
    };
    
    MovableSprite::MovableSprite(const std::string& texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Point currentPosition,SDL_Point acceleration): Sprite(texturePath, rectangle, currentPosition, true), acceleration(acceleration), bounds(bounds), accelerating(false), reversing(false), turningLeft(false), turningRight(false){
    }
    
    SDL_Rect MovableSprite::getBounds() const {
        return bounds;
    }
    
    int MovableSprite::getXAcc() const{
        return acceleration.x;
    }
    
    int MovableSprite::getYAcc() const {
        return acceleration.y;
    }
    
    void MovableSprite::setXacc(double newAcc){
        acceleration.x = newAcc;
    }
    
    void MovableSprite::setYacc(double newAcc){
        acceleration.y = newAcc;
    }
    
    void MovableSprite::setAccelerating(bool acc){
        accelerating =acc;
    }
    
    void MovableSprite::setReversing(bool reverse){
        reversing = reverse;
    }
    
    void MovableSprite::setTurningRight(bool right){
        turningRight = right;
    }
    
    void MovableSprite::setTurningLeft(bool left){
        turningLeft = left;
    }
    
    void MovableSprite::move(){
        if(accelerating && turningRight){
            accelerateRight();
        }else if(accelerating && turningLeft){
            accelerateLeft();
        }else if(reversing && turningRight){
            reverseRight();
        } else if(reversing && turningLeft){
            reverseLeft();
        } else if(accelerating){
            accelerate();
        } else if(turningRight){
            turnRight();
        } else if(reversing){
            reverse();
        } else if(turningLeft){
            turnLeft();
        }
    }
    
    bool MovableSprite::isAccelerating(){
        return accelerating;
    }
    
    bool MovableSprite::isReversing(){
        return reversing;
    }
    
    bool MovableSprite::isTurningLeft(){
        return turningLeft;
    }
    
    bool MovableSprite::isTurningRight(){
        return turningRight;
    }
    
    void MovableSprite::accelerateRight(){
        turnRight();
        accelerate();
    }
    
    void MovableSprite::accelerateLeft(){
        turnLeft();
        accelerate();
    }
    
    void MovableSprite::reverseRight(){
        turnRight();
        reverse();
    }
    
    void MovableSprite::reverseLeft(){
        turnLeft();
        reverse();
    }
    
    void MovableSprite::turnLeft(){
        SDL_Point pos = getCurrentPosition();
        int xAcc = getXAcc();
        setPosition({pos.x - xAcc, pos.y});
    }
    
    void MovableSprite::turnRight(){
        SDL_Point pos = getCurrentPosition();
        setPosition({pos.x + getXAcc(), pos.y});
    }
    
    void MovableSprite::reverse() {
        SDL_Point pos = getCurrentPosition();
        setPosition({pos.x, pos.y + getYAcc()});
    }
    
    void MovableSprite::accelerate(){
        SDL_Point pos = getCurrentPosition();
        setPosition({pos.x, pos.y - getYAcc()});
    }
    
    void MovableSprite::tick(GameEngine* gameEngine){
        SDL_Point willGoOut = goingOutOfBounds();
        if(willGoOut.x != 0 || willGoOut.y != 0){
            willGoOutOfBounds(willGoOut);
        }
        move();
        SDL_Point didGoOut = isOutOfBounds();
        if(didGoOut.x != 0 || didGoOut.y != 0){
            didGoOutOfBounds(didGoOut);
        }
    }
    
    shared_ptr<MovableSprite> MovableSprite::getInstance(const string& texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Point currentPosition, SDL_Point acceleration)
    {
        return shared_ptr<MovableSprite>(new MovableSprite(texturePath, bounds,rectangle, currentPosition, acceleration));
    }
    


}

