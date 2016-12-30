//
//  Meteor.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-28.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef Meteor_hpp
#define Meteor_hpp

#include "RotatingSprite.hpp"
#include "MovableSprite.hpp"
#include "Entity.hpp"
#include "Explodable.hpp"
#include "GameEngine.hpp"

class Meteor: public engine::MovableSprite, public engine::RotatingSprite, public Entity, public Explodable {
public:
    Meteor(const std::string texturePath, SDL_Rect bounds, SDL_Rect rectangle,SDL_Point currentPosition, SDL_Point acceleration, int rotationSpeed, std::function<void(std::shared_ptr<Entity>)>);
    void tick(engine::GameEngine*) override;
    void didCollideWith(std::shared_ptr<Sprite>) override;
protected:
    void didGoOutOfBounds(SDL_Point) override;
private:
    std::function<void(std::shared_ptr<Entity>)> onKilledCallback;
};

#endif /* Meteor_hpp */
