//
//  Explodable.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef Explodable_hpp
#define Explodable_hpp

#include "GameEngine.hpp"

class Explodable: virtual public engine::Sprite {
public:
    Explodable(std::function<void()> = nullptr);
    void explode(engine::GameEngine*);
protected:
    bool shouldExplode() const;
    void setShouldExplode(bool);
private:
    bool shouldPerformExplosion;
    const std::string explosionSheetPath = "resources/Spritesheet/explosion.png";
    const SDL_Point EXPLOSION_SIZE = {130,133};
    std::vector<SDL_Rect> explosionRects;
    std::function<void()> explosionFinishedCallback;
};

#endif /* Explodable_hpp */
