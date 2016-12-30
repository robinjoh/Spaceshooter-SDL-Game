//
//  AssetManager.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-24.
//  Copyright © 2016 Robin. All rights reserved.
//
#include "ResourceManager.hpp"
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL.h>
#include "Graphics.hpp"
#include "GameEngine.hpp"
#include <iostream>

using namespace std;

namespace engine {
    
    ResourceManager::ResourceManager(): loadedTextures(){}
    
    ResourceManager::~ResourceManager(){
        for(auto iter = loadedTextures.begin(); iter != loadedTextures.end(); iter++){
            SDL_DestroyTexture(iter->second);
        }
    }
    
    SDL_Texture* ResourceManager::loadTexture(const string& resourcePath){
        SDL_Texture* texture;
        if(!resourceExists(resourcePath, loadedTextures)){
            texture = IMG_LoadTexture(graphics.getRenderer(), resourcePath.c_str());
        } else {
            return loadedTextures[resourcePath];
        }
        if(texture == nullptr){
            printMessage("Could not load texture ");
            return nullptr;
        }
        loadedTextures.insert(make_pair(resourcePath, texture));
        return texture;
    }
    
}

