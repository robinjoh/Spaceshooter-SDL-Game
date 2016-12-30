//
//  SceneManager.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-21.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef LevelManager_hpp
#define LevelManager_hpp

#include <unordered_map>
#include <SDL2/SDL.h>

namespace engine{
    class Scene;
    class GameEngine;
    class Sprite;
class LevelManager {
public:
    LevelManager();
    ~LevelManager();
    void addScene(int sceneIdentifier, std::shared_ptr<Scene> scene);
    std::shared_ptr<Scene> getCurrentScene() const;
    void setScene(int sceneIdentifier);
    void handleDispatchedEvent(const SDL_Event& event);
private:
    std::shared_ptr<Scene> currentScene;
    std::unordered_map<int, std::shared_ptr<Scene>> scenes;
};
}

#endif /* LevelManager_hpp */
