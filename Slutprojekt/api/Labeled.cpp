//
//  Labeled.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-01.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "Labeled.hpp"
#include "Graphics.hpp"
using namespace std;

namespace engine {
    
    Labeled::~Labeled(){
        TTF_CloseFont(font);
        SDL_DestroyTexture(getTexture());
    }
    
    Labeled::Labeled(const string& fontPath, SDL_Rect rectangle, int fontSize,SDL_Color& textColor, string text):Sprite(fontPath, rectangle, {rectangle.x, rectangle.y}),fontSize(fontSize), text(text), textColor(textColor), font(nullptr){}
    
    void Labeled::draw(){
        SDL_Rect dest = getRect();
        SDL_RenderCopy(graphics.getRenderer(), getTexture(), NULL, &dest);
    }
    
    void Labeled::loadResources(ResourceManager& resourceManager){
        if(font != nullptr){
            TTF_CloseFont(font);
        }
        font = TTF_OpenFont(getTexturePath().c_str(), fontSize);
        if(font == nullptr){
            throw runtime_error("Unable to load font");
        }
        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(),textColor);
        if(surface == nullptr){
            throw new runtime_error("unable to create font surface");
        }
        SDL_Texture* tx = SDL_CreateTextureFromSurface(graphics.getRenderer(), surface);
        SDL_FreeSurface(surface);
        if(tx == nullptr){
            throw new runtime_error("Unable to create font texture");
        }
        int w,h;
        setTexture(tx);
        SDL_QueryTexture(getTexture(), NULL, NULL, &w, &h);
        setRectangle({getRect().x, getRect().y, w, h});
    }
    
    
    void Labeled::setText(const string& newText){
        text = newText;
        if(font == nullptr ||text == ""){
            return;
        }
        SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), textColor);
        if(surf == nullptr){
            throw runtime_error("Couldnt create text surface");
        }
        SDL_Texture* txt = (SDL_CreateTextureFromSurface(graphics.getRenderer(), surf));
        SDL_FreeSurface(surf);
        if(txt == nullptr){
            TTF_CloseFont(font);
            throw runtime_error("Couldnt create texture from surface.");
        }
        int w,h;
        SDL_QueryTexture(txt, NULL, NULL, &w, &h);
        SDL_Rect rect = {getRect().x, getRect().y, w, h};
        setTexture(txt);
        setRectangle(rect);
    }
    
    string Labeled::getText() const {
        return text;
    }
    
    void Labeled::setTextColor(const SDL_Color& color){
        textColor = color;
        setText(getText());
    }
}
