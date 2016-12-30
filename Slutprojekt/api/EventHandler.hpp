//
//  EventHandler.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//
#ifndef EventHandler_hpp
#define EventHandler_hpp

#include <map>
#include <SDL2/SDL.h>
#include <list>
#include <unordered_map>

namespace engine {
    class Sprite;
    class EventHandler {
    public:
        EventHandler();
        void handleEvents(std::list<std::shared_ptr<Sprite>>& sprites);
        void mapFunction(SDL_Keycode keycode, std::function<void()> ptr);
    private:
        std::unordered_map<SDL_Keycode, std::function<void()>> mappedCommands;
        void forwardEvent(SDL_Event &event, std::list<std::shared_ptr<Sprite>>& sprites);
    };
}
#endif /* EventHandler_hpp */


