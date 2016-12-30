//
//  Enemy.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp


#include "SpaceShuttle.hpp"
#include "Entity.hpp"

class Enemy: public SpaceShuttle {
public:
    Enemy(const std::string texturePath, SDL_Rect bounds, SDL_Rect rectangle,SDL_Rect shotRect,SDL_Rect shotImpactRect, SDL_Point currentPosition, SDL_Point acceleration, bool shooting, int shootingDelay, std::function<void(std::shared_ptr<Entity>)>);
    void tick(engine::GameEngine* gameEngine)override;
    void didCollideWith(std::shared_ptr<Sprite>)override;
protected:
    void didGoOutOfBounds(SDL_Point) override;
private:
    std::function<void(std::shared_ptr<Enemy>)> collideWithPlayerProjectileCallback;
    SDL_Rect shotRect;
    int shotSpeed = 3;
    SDL_Rect shotImpactRect;
};


#endif /* Enemy_hpp */

