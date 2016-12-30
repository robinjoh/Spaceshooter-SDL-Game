//
//  ScrollingBackgroundSprite.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-02.
//  Copyright © 2016 Robin. All rights reserved.
//
#include "Graphics.hpp"
#include "GameEngine.hpp"
#include "ScrollingBackgroundSprite.hpp"
#include "ScrollingDirection.hpp"
using namespace std;
namespace engine {
    
    ScrollingBackgroundSprite::ScrollingBackgroundSprite(const string& resourcePath, SDL_Rect rectangle, SDL_Point currentPosition, ScrollingDirection scrollingDirection): Sprite(resourcePath, rectangle, currentPosition), scrollingOffset(0), scrollingDirection(scrollingDirection){}
    
    void ScrollingBackgroundSprite::draw(){
        SDL_Renderer* renderer = graphics.getRenderer();
        SDL_Rect dest = getRect();
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, getTexture(), NULL, &dest);
        if(scrollingDirection == ScrollingDirection::HORIZONTAL){
            dest.x = -dest.w + scrollingOffset;
        } else {
            dest.y = -dest.h + scrollingOffset;
        }
        SDL_RenderCopy(renderer, getTexture(), NULL, &dest);
    }
    
    void ScrollingBackgroundSprite::tick(GameEngine* gameEngine){
        SDL_Rect rect = getRect();
        switch(scrollingDirection){
            case HORIZONTAL:
                if(scrollingOffset == getRect().w){
                    scrollingOffset = 0;
                }
                rect.x = scrollingOffset;
                setRectangle(rect);
                break;
            case VERTICAL:
                if(scrollingOffset == getRect().h){
                    scrollingOffset = 0;
                }
                rect.y = scrollingOffset;
                setRectangle(rect);
                break;
        }
        scrollingOffset++;
    }
    
    shared_ptr<ScrollingBackgroundSprite> ScrollingBackgroundSprite::getInstance(const std::string &resourcePath, SDL_Rect rectangle, SDL_Point currentPosition, engine::ScrollingDirection scrollDirection){
        return shared_ptr<ScrollingBackgroundSprite>(new ScrollingBackgroundSprite(resourcePath, rectangle, currentPosition, scrollDirection));
    }
    
}
