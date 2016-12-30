 //
//  Scene.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "Scene.hpp"
#include <SDL2_image/SDL_image.h>
#include "Graphics.hpp"
#include "Sprite.hpp"
#include "ScrollingBackgroundSprite.hpp"

using namespace std;

namespace engine {
    
    Scene::Scene(shared_ptr<Sprite> background, SDL_Rect rect):background(background), rectangle(rect){
    }
    
    void Scene::update(GameEngine* gameEngine) {
        background->tick(gameEngine);
        for(auto sprite : sprites){
            sprite->tick(gameEngine);
        }
    }
    
    void Scene::draw() {
        background->draw();
        for(auto iter : sprites){
            iter->draw();
        }
    }
    
    void Scene::addSprite(shared_ptr<Sprite> sprite){
        sprites.push_back(sprite);
    }

    void Scene::removeSprite(shared_ptr<Sprite> sprite){
        sprites.erase(std::remove(sprites.begin(), sprites.end(), sprite), sprites.end());
    }
    
    shared_ptr<Sprite> Scene::getBackground() const {
        return background;
    }
    
    SDL_Rect Scene::getRect() const { return rectangle;}
    
    
    
    list<shared_ptr<Sprite>> Scene::getSprites() {
        return sprites;
    }
    
    void Scene::clear(){
        sprites.clear();
    }
}
