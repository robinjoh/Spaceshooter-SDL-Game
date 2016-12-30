//
//  Slutprojekt
//
//  Created by Robin on 2016-11-24.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

namespace engine {
class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();
    SDL_Texture* loadTexture(const std::string&);
    TTF_Font* loadFont(const std::string&, int);
private:
    std::unordered_map<std::string, SDL_Texture*> loadedTextures;
    template<typename T>
    bool resourceExists(const std::string resourcePath, std::unordered_map<std::string, T> map){
        return map.find(resourcePath) != map.end();
    }
};

}

#endif /* AssetManager_hpp */
