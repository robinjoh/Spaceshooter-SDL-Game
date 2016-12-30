//
//  StaticSprite.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-13.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "StaticSprite.hpp"
using namespace std;
namespace engine {
    
    shared_ptr<StaticSprite> StaticSprite::getInstance(const std::string &texturePath, SDL_Rect rectangle, SDL_Point currentPosition){
        return shared_ptr<StaticSprite>(new StaticSprite(texturePath, rectangle, currentPosition));
    }
    
    void StaticSprite::tick(GameEngine* engine){};
}
