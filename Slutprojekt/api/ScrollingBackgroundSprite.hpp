//
//  ScrollingBackgroundSprite.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-02.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef ScrollingBackgroundSprite_hpp
#define ScrollingBackgroundSprite_hpp
#include "ScrollingDirection.hpp"
#include "GameEngine.hpp"
#include "Sprite.hpp"
namespace engine {
    class ScrollingBackgroundSprite: public Sprite {
    public:
        void draw();
        void tick(GameEngine* gameEngine);
        static std::shared_ptr<ScrollingBackgroundSprite> getInstance(const std::string& resourcePath, SDL_Rect rectangle, SDL_Point currentPosition, ScrollingDirection scrollDirection);
    protected:
        ScrollingBackgroundSprite(const std::string& resourcePath, SDL_Rect rectangle, SDL_Point currentPosition, ScrollingDirection scrollDirection);
        
    private:
        int scrollingOffset;
        ScrollingDirection scrollingDirection;
        ScrollingBackgroundSprite(const ScrollingBackgroundSprite&other) = delete;
        const ScrollingBackgroundSprite& operator=(const ScrollingBackgroundSprite& other) = delete;
    };
    
}
#endif /* ScrollingBackgroundSprite_hpp */
