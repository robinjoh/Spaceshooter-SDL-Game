//
//  Graphics.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-27.
//  Copyright © 2016 Robin. All rights reserved.
//
#include "Graphics.hpp"
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "GameEngine.hpp"

using namespace std;

namespace engine {
    
    Graphics::Graphics(){
        if(!loadLibraries()){
            throw runtime_error("Could not load libraries");
        }
        SDL_DisplayMode current;
        SDL_GetCurrentDisplayMode(0, &current);
        windowRect = {0,0,current.w, current.h};
        window = SDL_CreateWindow(DEFAULT_WINDOW_TITLE.c_str(), windowRect.x, windowRect.y, windowRect.w, windowRect.h, SDL_WINDOW_HIDDEN);
        if(window == nullptr){
            throw runtime_error("Unable to create window");
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        if(renderer == nullptr){
            throw runtime_error("Unable to create renderer.");
        }
    }
    
    Graphics::~Graphics(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
    }
    
    void Graphics::showWindow(){
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        SDL_ShowWindow(window);
    }
    
    SDL_Renderer* Graphics::getRenderer() const {
        return renderer;
    }
    
    bool Graphics::loadLibraries() {
        printMessage("Loading libraries and images...");
        return loadSDL() && loadIMG() && loadTTF();
    }
    
    bool Graphics::loadIMG(){
        if (IMG_Init(0) == 0) {
            printMessage("Image library loaded.");
            return true;
        }
        return false;
    }
    
    bool Graphics::loadSDL(){
        if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
            printMessage("SDL library loaded.");
            return true;
        }
        return false;
    }
    
    bool Graphics::loadTTF(){
        if (TTF_Init() == 0){
            printMessage("TTF library loaded.");
            return true;
        }
        return false;
    }
    
    
    void Graphics::setWindowTitle(const std::string &title) {
        SDL_SetWindowTitle(window, title.c_str());
    }
    
    void Graphics::setWindowSize(const SDL_Rect &rect) {
        SDL_SetWindowSize(window, rect.w, rect.h);
    }
    
    SDL_Rect Graphics::getScreenSize(){
        return windowRect;
    }
    
    Graphics graphics;
}
