//
//  RotatingSprite.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-28.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef RotatingSprite_hpp
#define RotatingSprite_hpp

#include "Sprite.hpp"
#include <SDL2/SDL.h>
#include <string>

namespace engine {
    class RotatingSprite: virtual public Sprite {
    public:
        void tick(GameEngine* gameEngine);
        void draw();
        static std::shared_ptr<RotatingSprite> getInstance(const std::string&, SDL_Rect, SDL_Point, int);
    protected:
        RotatingSprite(const std::string&, SDL_Rect, SDL_Point, int);
    private:
        int rotationSpeed;
        int currentAngle;
    };
}

#endif /* RotatingSprite_hpp */
