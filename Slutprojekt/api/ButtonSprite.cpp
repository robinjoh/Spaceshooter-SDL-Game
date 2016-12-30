//
//  ButtonSprite.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-05.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "ButtonSprite.hpp"
#include "Graphics.hpp"

using namespace std;
namespace engine {
    
    ButtonSprite::ButtonSprite(const string& texturePath, const string& fontPath, string& text, SDL_Rect rect, int fontSize,SDL_Point position, SDL_Color textColor, SDL_Color buttonPressedColor,function<void()> onReleaseCallback, function<void()> onPressedCallback): Labeled(fontPath, {position.x, position.y, rect.w, rect.h}, fontSize, textColor, text),buttonTexturePath(texturePath), onReleaseCallback(onReleaseCallback), onPressedCallback(onPressedCallback), rect(rect), colorOnPress(buttonPressedColor), pressed(false) {
    }
    
    void ButtonSprite::tick(GameEngine *gameEngine){
        
    }
    
    void ButtonSprite::draw(){
        SDL_Rect dest = rect;
        dest.x = getCurrentPosition().x;
        dest.y = getCurrentPosition().y;
        SDL_Rect src = rect;
        SDL_RenderCopy(graphics.getRenderer(), buttonTexture,&src, &dest);
        Labeled::draw();
    }
    
    void ButtonSprite::handleEvent(SDL_Event & eve){
        SDL_Point click = {eve.button.x, eve.button.y};
        SDL_Rect rectangle = {getCurrentPosition().x, getCurrentPosition().y, rect.w, rect.h};
        switch(eve.type){
            case SDL_MOUSEBUTTONDOWN:
                if(SDL_PointInRect(&click, &rectangle)){
                    pressed = true;
                    SDL_Color tmp = getTextColor();
                    setTextColor(colorOnPress);
                    colorOnPress = tmp;
                    if(onPressedCallback != nullptr){
                        onPressedCallback();
                    }
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if(pressed){
                    SDL_Color tmp = getTextColor();
                    setTextColor(colorOnPress);
                    colorOnPress = tmp;
                    if(SDL_PointInRect(&click, &rectangle)){
                        if(onReleaseCallback != nullptr){
                            onReleaseCallback();
                        }
                    }
                    pressed=false;
                }
                break;
        }
    }
    
    void ButtonSprite::loadResources(ResourceManager & resourceManager){
        Labeled::loadResources(resourceManager);
        buttonTexture = resourceManager.loadTexture(buttonTexturePath);
        if(buttonTexture == nullptr){
            throw runtime_error("Could not load button texture.");
        }
        setRectangle({getCurrentPosition().x + rect.w / 2 - getRect().w / 2, getCurrentPosition().y + rect.h / 2 - getRect().h / 2, getRect().w, getRect().h});
    }
    shared_ptr<ButtonSprite> ButtonSprite::getInstance(const std::string&texturePath, const std::string& fontPath, std::string& text, SDL_Rect rect, int fontSize,SDL_Point position,SDL_Color textColor, SDL_Color colorOnPress,std::function<void()> onReleaseCallback, std::function<void()> onPressedCallback){
        return shared_ptr<ButtonSprite>(new ButtonSprite(texturePath, fontPath, text, rect, fontSize, position, textColor, colorOnPress, onReleaseCallback, onPressedCallback));
    }
    
    void ButtonSprite::setOnReleaseCallback(std::function<void ()> newCallback){
        onReleaseCallback = newCallback;
    }
    
    void ButtonSprite::setText(std::string &&newText){
        Labeled::setText(newText);
        setRectangle({getCurrentPosition().x + rect.w/2 - getRect().w / 2, getCurrentPosition().y + rect.h / 2 - getRect().h / 2,getRect().w, getRect().h});
    }
    
    
}
