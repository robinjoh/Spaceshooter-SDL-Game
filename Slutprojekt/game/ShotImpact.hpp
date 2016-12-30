//
//  ShotImpact.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-10.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef ShotImpact_hpp
#define ShotImpact_hpp

#include "StaticSprite.hpp"

class ShotImpact: public engine::StaticSprite {
public:
    ShotImpact(const std::string texturePath, SDL_Rect rectangle, SDL_Point currentPosition);
    void tick(engine::GameEngine* gameEngine);
private:
    int lifeTime = 5;
};

#endif /* ShotImpact_hpp */
