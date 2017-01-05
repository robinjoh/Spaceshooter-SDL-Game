//
//  StaticSprite.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-13.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef StaticSprite_hpp
#define StaticSprite_hpp

#include "Sprite.hpp"
namespace engine {
    class StaticSprite: public Sprite {
        public:
        static std::shared_ptr<StaticSprite> getInstance(const std::string& texturePath, SDL_Rect rectangle, SDL_Point currentPosition);
        void tick(GameEngine*) override;
        protected:
        using Sprite::Sprite;
    };
}

#endif /* StaticSprite_hpp */
