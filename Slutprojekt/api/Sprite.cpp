 
//  Sprite.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//
#include "Graphics.hpp"
#include "Sprite.hpp"
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

namespace engine {
    
    Sprite::Sprite(const string& texturePath,SDL_Rect rectangle, SDL_Point currentPosition, bool collidable): rectangle(rectangle),currentPosition(currentPosition), texturePath(texturePath), texture(nullptr), currentTick(0), collidable(collidable) {}
    
    void Sprite::draw(){
        SDL_Renderer* rend = graphics.getRenderer();
        SDL_Rect dest = {currentPosition.x, currentPosition.y, rectangle.w, rectangle.h};
        SDL_RenderCopy(rend, texture, &rectangle, &dest);
    }
    
    Sprite::~Sprite(){};
    
    SDL_Texture* Sprite::getTexture() const {
        return texture;
    }
    
    SDL_Point Sprite::getCurrentPosition() const {
        return currentPosition;
    }
    
    SDL_Rect Sprite::getRect() const {
        return rectangle;
    }
    
    bool Sprite::isCollidable() const {
        return collidable;
    }
    
    int Sprite::getCurrentTick() const {
        return currentTick;
    }
    
    void Sprite::setCurrentTick(int newTick){
        currentTick = newTick;
    }
    
    string Sprite::getTexturePath() const {
        return texturePath;
    }
    
    void Sprite::setPosition(SDL_Point newPos){
        currentPosition = newPos;
    }
    
    void Sprite::setRectangle(SDL_Rect newRect){
        rectangle = newRect;
    }
    
    void Sprite::setTexture(SDL_Texture* tex){
        if(texture != nullptr){
            SDL_DestroyTexture(texture);
        }
        texture = tex;
    }
    
    void Sprite::loadResources(ResourceManager& resourceManager){
        if(texture != nullptr){
            return;
        }
        SDL_Texture* text = resourceManager.loadTexture(texturePath);
        if(text != nullptr) {
            setTexture(text);
        } else {
            throw runtime_error("Unable to load texture.");
        }
    }
}
