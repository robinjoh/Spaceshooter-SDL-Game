//
//  EnemyShot.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-07.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef EnemyShot_hpp
#define EnemyShot_hpp
#include "MovableSprite.hpp"
#include "Entity.hpp"

class EnemyShot: virtual public Entity,public engine::MovableSprite {
public:
    void tick(engine::GameEngine*);
    EnemyShot(const std::string texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Rect impactRect,SDL_Point currentPosition, SDL_Point acceleration);
    void didCollideWith(std::shared_ptr<engine::Sprite>);
protected:
    void didGoOutOfBounds(SDL_Point);
private:
    SDL_Rect impactRect;
    bool spawnImpact;
};
#endif /* EnemyShot_hpp */
