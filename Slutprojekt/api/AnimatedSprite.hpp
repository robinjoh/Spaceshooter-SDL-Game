//
//  AnimatedSprite.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-21.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef AnimatedSprite_hpp
#define AnimatedSprite_hpp

#include "Sprite.hpp"

namespace engine {
    class AnimatedSprite: virtual public Sprite {
    public:
        ~AnimatedSprite();
        void tick(GameEngine* gameEngine);
        static std::shared_ptr<AnimatedSprite> getInstance(const std::string&, SDL_Rect, SDL_Point, std::vector<SDL_Rect>, int,int, std::function<void()>);
    protected:
        AnimatedSprite(const std::string&, SDL_Rect, SDL_Point, std::vector<SDL_Rect>, int animateNrOfTimes,int animationInterval, std::function<void()> onFinishCallback = nullptr);
        void setAnimationRect(int rectNr);
        void draw();
        void addRectToAnimate(int rectNr);
        int getCurrentRectNr() const;
        long getNumberOfRects() const;
    private:
        int currentRectNr;
        int animationInterval;
        int currentLoop;
        int animateNrOfTimes;
        SDL_Rect currentRect;
        std::function<void()> onFinishCallback;
        std::vector<SDL_Rect> sourceRects;
        AnimatedSprite(const AnimatedSprite& other) = delete;
        const AnimatedSprite& operator=(const AnimatedSprite& other) = delete;
    };
}

#endif /* AnimatedSprite_hpp */
