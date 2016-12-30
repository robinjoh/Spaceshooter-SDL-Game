//
//  RotatingSprite.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-28.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "RotatingSprite.hpp"
#include "Graphics.hpp"

using namespace std;

namespace engine {

    RotatingSprite::RotatingSprite(const string& texturePath, SDL_Rect rectangle, SDL_Point currentPosition, int rotationSpeed): Sprite(texturePath, rectangle, currentPosition),rotationSpeed(rotationSpeed), currentAngle(0) {}
    
    void RotatingSprite::draw(){
        SDL_Point center = {getRect().w / 2, getRect().h / 2};
        SDL_Rect src = getRect();
        SDL_Rect dest = {getCurrentPosition().x, getCurrentPosition().y, getRect().w, getRect().h};
        SDL_RenderCopyEx(graphics.getRenderer(), getTexture(), &src, &dest, currentAngle, &center, SDL_FLIP_NONE);
    }
 
    void RotatingSprite::tick(GameEngine* gameEngine){
        currentAngle += rotationSpeed;
    }
    
    shared_ptr<RotatingSprite>  RotatingSprite::getInstance(const std::string& texturePath, SDL_Rect rectangle, SDL_Point currentPosition, int rotationSpeed){
        return shared_ptr<RotatingSprite>(new RotatingSprite(texturePath, rectangle, currentPosition, rotationSpeed));
    }
    
}
