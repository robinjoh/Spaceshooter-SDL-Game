//
//  AnimatedSprite.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-21.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "AnimatedSprite.hpp"
#include "Graphics.hpp"
using namespace std;

namespace engine {
    
    AnimatedSprite::~AnimatedSprite(){
        if(onFinishCallback != nullptr){
            onFinishCallback();
        }
    }
    
    AnimatedSprite::AnimatedSprite(const std::string& texturePath, SDL_Rect rectangle, SDL_Point currentPosition,std::vector<SDL_Rect> animationRects, int animateNrOfTimes,int animationInterval,function<void()> onFinishCallback):Sprite(texturePath, rectangle, currentPosition),sourceRects(animationRects), animationInterval(animationInterval), currentRectNr(0), animateNrOfTimes(animateNrOfTimes), onFinishCallback(onFinishCallback), currentLoop(0){
        currentRect = animationRects[0];
    }
    
    void AnimatedSprite::setAnimationRect(int rectNr){
        if(rectNr < sourceRects.size()-1){
            currentRect = sourceRects[rectNr];
            setRectangle(currentRect);
            currentRectNr = rectNr;
        }
    }
    
    shared_ptr<AnimatedSprite> AnimatedSprite::getInstance(const std::string & texturePath, SDL_Rect rectangle, SDL_Point position, std::vector<SDL_Rect> animationFrames, int repeatAnimation,int animationInterval, std::function<void()> onFinishCallback){
        return shared_ptr<AnimatedSprite>(new AnimatedSprite(texturePath, rectangle, position,animationFrames, repeatAnimation,animationInterval, onFinishCallback));
    }
    
    int AnimatedSprite::getCurrentRectNr() const{
        return currentRectNr;
    }
    
    long AnimatedSprite::getNumberOfRects() const {
        return sourceRects.size();
    }
    
    void AnimatedSprite::draw(){
        SDL_Rect dest = {getCurrentPosition().x, getCurrentPosition().y, getRect().w, getRect().h};
        SDL_RenderCopy(graphics.getRenderer(), getTexture(), &currentRect, &dest);
    }
    
    void AnimatedSprite::tick(GameEngine *gameEngine){
        setCurrentTick(getCurrentTick()+1);
        if(getCurrentTick() >= animationInterval){
            if(currentRectNr == sourceRects.size()-1){
                currentLoop++;
                if(animateNrOfTimes != 0 && animateNrOfTimes == currentLoop){
                    gameEngine->deleteSprite(shared_from_this());
                }
                currentRectNr = 0;
            } else {
                currentRectNr++;
            }
            currentRect = sourceRects[currentRectNr];
            setCurrentTick(0);
        }
    }
}
