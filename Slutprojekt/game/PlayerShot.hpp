//
//  PlayerShot.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-28.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef PlayerShot_hpp
#define PlayerShot_hpp

#include "MovableSprite.hpp"
#include "Entity.hpp"
#include "Game.hpp"

class PlayerShot: public Entity, public engine::MovableSprite {
public:
    PlayerShot(const std::string texturePath, SDL_Rect, SDL_Rect ,SDL_Rect, SDL_Point currentPosition, SDL_Point acceleration);
    void tick(engine::GameEngine*) override;
    void didCollideWith(std::shared_ptr<Sprite>) override;
protected:
    void didGoOutOfBounds(SDL_Point) override;
private:
    bool spawnImpact;
    SDL_Rect impactSrcRect;
    std::string impactTexturePath;
};

#endif /* PlayerShot_hpp */
