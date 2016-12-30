//
//  Scene.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//
#ifndef Scene_hpp
#define Scene_hpp

#include <SDL2/SDL.h>
#include <list>
#include <string>
#include "ResourceManager.hpp"

namespace engine {
    class Sprite;
    class GameEngine;
	class Scene {
	public:
        Scene(std::shared_ptr<Sprite> background, SDL_Rect rectangle);
        void addSprite(std::shared_ptr<Sprite> sprite);
        void removeSprite(std::shared_ptr<Sprite> sprite);
        void update(GameEngine* gameEngine);
		void draw();
        void clear();
		SDL_Rect getRect() const;
        std::shared_ptr<Sprite> getBackground() const;
        std::list<std::shared_ptr<Sprite>> getSprites();
        void handleEvent(const SDL_Event& event);
	private:
        std::shared_ptr<Sprite> background;
        std::list<std::shared_ptr<Sprite>> sprites;
		SDL_Rect rectangle;
	};
}
#endif /* Scene_hpp */
