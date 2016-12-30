//
//  SceneManager.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-21.
//  Copyright © 2016 Robin. All rights reserved.
//
#include "Scene.hpp"
#include "LevelManager.hpp"
#include <iostream>

using namespace std;

namespace engine {

    LevelManager::LevelManager(): currentScene(){}
    
    LevelManager::~LevelManager(){}
    
    void LevelManager::addScene(int sceneIdentifier, shared_ptr<Scene> scene){
        scenes[sceneIdentifier] = scene;
    }
    
    shared_ptr<Scene> LevelManager::getCurrentScene() const {
        return currentScene;
    }
    
    void LevelManager::setScene(int sceneIdentifier){
        if(scenes.find(sceneIdentifier) != scenes.end()){
            currentScene = scenes[sceneIdentifier];
        }
    }
    
}
