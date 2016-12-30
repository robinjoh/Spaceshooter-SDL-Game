//
//  LabelSprite.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-13.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "LabelSprite.hpp"
#include "Graphics.hpp"

using namespace std;
namespace engine {
    
    LabelSprite::LabelSprite(const std::string& fontPath, SDL_Rect rect, int fontSize, SDL_Color color, std::string text): Labeled(fontPath, rect, fontSize,color,text){}
    
    void LabelSprite::tick(engine::GameEngine * gameEngine){
    }
    
    void LabelSprite::draw(){
        SDL_Rect dest = getRect();
        dest.x = getCurrentPosition().x;
        dest.y = getCurrentPosition().y;
        SDL_RenderCopy(graphics.getRenderer(), getTexture(), NULL, &dest);
    }
    
    shared_ptr<LabelSprite> LabelSprite::getInstance(const string&fontPath, SDL_Rect rect, int fontSize, SDL_Color& color, string text){
        return shared_ptr<LabelSprite>(new LabelSprite(fontPath, rect, fontSize, color, text));
    }
}
