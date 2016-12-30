//
//  Sprite.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//
#ifndef Sprite_hpp
#define Sprite_hpp

#include <vector>
#include <SDL2/SDL.h>
#include <string>
#include "ResourceManager.hpp"
#include "GameEngine.hpp"

namespace engine {
    class Sprite: public std::enable_shared_from_this<Sprite> {
    public:
        virtual ~Sprite();
        virtual void tick(GameEngine*) = 0;
        virtual void loadResources(ResourceManager&);
        virtual void draw();
        virtual void handleEvent(SDL_Event& event){};
        virtual void didCollideWith(std::shared_ptr<Sprite> otherSprite) {}; //override to handle collisions.
        SDL_Point getCurrentPosition() const;
        SDL_Rect getRect() const;
        void setPosition(SDL_Point newPos);
        std::string getTexturePath() const;
        void setRectangle(SDL_Rect newRectangle);
        bool isCollidable() const;
    protected:
        Sprite(const std::string& texturePath, SDL_Rect rectangle, SDL_Point currentPosition, bool collidable = false);
        SDL_Texture* getTexture() const;
        int getCurrentTick() const;
        void setCurrentTick(int newTick);
        void setTexture(SDL_Texture* texture);
    private:
        bool collidable;
        int currentTick;
        SDL_Texture* texture;
        const std::string texturePath;
        SDL_Point currentPosition;
        SDL_Rect rectangle;
    };
}
#endif /* Sprite_hpp */
