//
//  MovableSprite.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef MovableSprite_hpp
#define MovableSprite_hpp

#include "Sprite.hpp"

namespace engine {
    class MovableSprite: virtual public Sprite {
    public:
        int getXAcc() const;
        int getYAcc() const;
        void setXacc(double newAcc);
        void setYacc(double newAcc);
        SDL_Rect getBounds() const;
        void tick(engine::GameEngine* gameEngine) override;
        static std::shared_ptr<MovableSprite> getInstance(const std::string&, SDL_Rect, SDL_Rect, SDL_Point, SDL_Point);
        void setAccelerating(bool);
        void setReversing(bool);
        void setTurningRight(bool);
        void setTurningLeft(bool);
        bool isAccelerating();
        bool isReversing();
        bool isTurningLeft();
        bool isTurningRight();
    protected:
        void move();
        void accelerateRight();
        void accelerateLeft();
        void reverseRight();
        void reverseLeft();
        void turnLeft();
        void turnRight();
        void reverse();
        void accelerate();
        virtual void willGoOutOfBounds(SDL_Point at){}; // override to take action when sprite will go out of bounds.
        virtual void didGoOutOfBounds(SDL_Point at){};//override to take action when sprite moved outside its bounds.
        MovableSprite(const std::string&, SDL_Rect, SDL_Rect, SDL_Point, SDL_Point);
    private:
        SDL_Rect bounds;
        SDL_Point acceleration;
        bool accelerating;
        bool reversing;
        bool turningLeft;
        bool turningRight;
        const MovableSprite& operator=(const MovableSprite& other) = delete;
        MovableSprite(const MovableSprite& other) = delete;
        SDL_Point isOutOfBounds();
        SDL_Point goingOutOfBounds();
    };
}
#endif /* MovableSprite_hpp */
