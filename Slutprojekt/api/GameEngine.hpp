//
//  GameEngine.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef GameEngine_h
#define GameEngine_h
#include "LevelManager.hpp"
#include "ResourceManager.hpp"
#include "EventHandler.hpp"
#include "Scene.hpp"
#include "CollisionDetector.hpp"
#include "Sprite.hpp"
#include <SDL2/SDL.h>

namespace engine {
    void printMessage(std::string);
    class GameEngine {
    public:
        ~GameEngine();
        void setLevel(int level);
        void addSprite(std::shared_ptr<Sprite> sprite);
        void addSprite(Sprite*);
        void addLevel(const int levelIdentifier, std::shared_ptr<Scene> scene);
        void deleteSprite(std::shared_ptr<Sprite> sprite);
        void installKeyCommand(SDL_Keycode keyCode, std::function<  void()> ptr);
        void run();
        void terminate();
        SDL_Rect getScreenSize();
        void clearCurrentScene();
        static GameEngine* getInstance(const std::string windowTitle, const int fps = DEFAULT_FPS);
        SDL_TimerID installTimedCallback(int callbackInterval, std::function<void()>&);
        void removeTimedCallback(SDL_TimerID);
    private:
        GameEngine(const std::string windowTitle, const int fps);
        static const int DEFAULT_FPS = 60;
        const int SECOND_IN_MS = 1000;
        static GameEngine* instance;
        ResourceManager resourceManager;
        LevelManager levelManager;
        EventHandler eventHandler;
        CollisionDetector collisionDetector;
        std::list<std::shared_ptr<Sprite>> spritesToDelete;
        int fps;
        bool running = false;
        void deleteKilledSprites();
    };
    
}
#endif
