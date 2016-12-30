//
//  SpaceShip.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-05.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef SpaceShip_hpp
#define SpaceShip_hpp

#include "MovableSprite.hpp"
#include "Entity.hpp"
#include "Explodable.hpp"

class SpaceShuttle: public engine::MovableSprite, public Entity, public Explodable {
public:
    SpaceShuttle(const std::string texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Point currentPosition, SDL_Point acceleration, bool shooting,int shootingDelay, int killValue, int durability = 1,std::function<void()> = nullptr);
    int getShootingDelay() const;
    bool getShooting() const;
    void setShooting(bool shoot);
private:
    bool shooting;
    int shootingDelay;
};

#endif /* SpaceShip_hpp */
