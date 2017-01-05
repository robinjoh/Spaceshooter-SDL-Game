//
//  GameEngine.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-01.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "GameEngine.hpp"
#include "Graphics.hpp"
#include <iostream>
using namespace std;

namespace engine {
    
    void printMessage(std::string message){
        std::cout << message << std::endl;
    }
    
    Uint32 timerCallback(Uint32 interval, void*func){
        SDL_Event event;
        SDL_UserEvent userEvent;
        userEvent.data1 = static_cast<function<void()>*>(func);
        userEvent.type = SDL_USEREVENT;
        event.type = SDL_USEREVENT;
        event.user = userEvent;
        userEvent.code = 0;
        SDL_PushEvent(&event);
        return interval;
    }
    
    GameEngine* GameEngine::instance = nullptr;
    
    GameEngine::~GameEngine(){
        instance = nullptr;
    }
    
    GameEngine::GameEngine(const string windowTitle, int fps): fps(fps), resourceManager(), levelManager(), collisionDetector(){
        graphics.load(windowTitle);
    }
    
    void GameEngine::run(){
        running = true;
        graphics.showWindow();
        const int TIME_PER_FRAME = SECOND_IN_MS / fps;
        int nextTick = 0;
        while (running) {
            nextTick = TIME_PER_FRAME + SDL_GetTicks();
            shared_ptr<Scene> scene = levelManager.getCurrentScene();
            list<shared_ptr<Sprite>> sprites = scene->getSprites();
            collisionDetector.checkCollisions(sprites);
            deleteKilledSprites();
            eventHandler.handleEvents(sprites);
            scene->update(this);
            SDL_RenderClear(graphics.getRenderer());
            scene->draw();
            SDL_RenderPresent(graphics.getRenderer());
            int delay = nextTick - SDL_GetTicks();
            if(delay > 0){
                SDL_Delay(delay);
            }
        }
    }
    
    void GameEngine::addLevel(int levelIdentifier, shared_ptr<Scene> scene){
        scene->getBackground()->loadResources(resourceManager);
        for(shared_ptr<Sprite> sprite : scene->getSprites()){
            sprite->loadResources(resourceManager);
        }
        levelManager.addScene(levelIdentifier, scene);
    }
    
    void GameEngine::terminate(){
        running = false;
    }
    
    void GameEngine::deleteSprite(shared_ptr<Sprite> sprite){
        spritesToDelete.push_back(sprite);
        levelManager.getCurrentScene()->removeSprite(sprite);
    }
    
    void GameEngine::deleteKilledSprites(){
        spritesToDelete.clear();
    }
    
    void GameEngine::setLevel(int level){
        levelManager.setScene(level);
        
    }
    
    void GameEngine::clearCurrentScene() {
        if(levelManager.getCurrentScene() != nullptr){
            levelManager.getCurrentScene()->clear();
            deleteKilledSprites();
        }
    }
    
    GameEngine* GameEngine::getInstance(const std::string windowTitle, const int fps){
        if(!instance){
            instance = new GameEngine(windowTitle, fps);
        }
        return instance;
    }
    
    void GameEngine::addSprite(shared_ptr<Sprite> sprite){
        if(levelManager.getCurrentScene() != nullptr){
            sprite->loadResources(resourceManager);
            levelManager.getCurrentScene()->addSprite(sprite);
        } else {
            throw runtime_error("Unable to add a sprite to a non-existing scene.");
        }
    }
    
    void GameEngine::addSprite(Sprite* sprite){
        addSprite(shared_ptr<Sprite>(sprite));
    }
    
    SDL_Rect GameEngine::getScreenSize(){
        return graphics.getScreenSize();
    }
    
    
    SDL_TimerID GameEngine::installTimedCallback(int callbackInterval, std::function<void ()>& callback){
        return SDL_AddTimer(callbackInterval, timerCallback, &callback);
    }
    
    void GameEngine::removeTimedCallback(SDL_TimerID timer){
        SDL_RemoveTimer(timer);
    }
    
    
    void GameEngine::installKeyCommand(SDL_Keycode keyCode, std::function<void ()> ptr){
        eventHandler.mapFunction(keyCode, ptr);
    }
}
