//
//  EventHandler.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "EventHandler.hpp"
#include "Sprite.hpp"
#include <iostream>
using namespace std;
namespace engine {
    
    EventHandler::EventHandler(): mappedCommands(){}
    
    void EventHandler::handleEvents(list<shared_ptr<Sprite>>& sprites){
        SDL_Event eve;
        while(SDL_PollEvent(&eve)){
            auto iter = mappedCommands.find(eve.key.keysym.sym);
            if(iter != mappedCommands.end() && (eve.type == SDL_KEYDOWN)){
                iter->second();
            }else {
                switch(eve.type){
                    case SDL_QUIT:
                        SDL_Quit();
                        exit(0);
                    case SDL_USEREVENT:{
                        function<void()>* func = static_cast<function<void()>*>(eve.user.data1);
                        (*func)();
                    }
                    default:
                        forwardEvent(eve, sprites);
                        break;
                }
            }
        }
    }
    
    void EventHandler::mapFunction(SDL_Keycode keycode, std::function<void()> ptr){
        mappedCommands[keycode] = ptr;
    };
    
    void EventHandler::forwardEvent(SDL_Event &event, list<shared_ptr<Sprite>>& sprites) {
        for(shared_ptr<Sprite> sprite: sprites){
            sprite->handleEvent(event);
        }
    }
}
