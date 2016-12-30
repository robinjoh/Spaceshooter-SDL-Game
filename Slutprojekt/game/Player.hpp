//
//  Player.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-29.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "AnimatedSprite.hpp"
#include "SpaceShuttle.hpp"
#include "GameEngine.hpp"

class Player: public SpaceShuttle {
class Entity;
public:
    Player(const std::string texturePath, SDL_Rect bounds, SDL_Rect rectangle, SDL_Point currentPosition, SDL_Point acceleration, int shotSpawnRate, SDL_Rect, SDL_Rect, std::function<void()> explosionFinishedCallback);
    void tick(engine::GameEngine* gameEngine) override;
    void handleEvent(SDL_Event& event) override;
    void didCollideWith(std::shared_ptr<Sprite>) override;
protected:
    void willGoOutOfBounds(SDL_Point) override;
private:
    SDL_Rect projectileSourceRect;
    SDL_Rect shotImpactRect;
    std::function<void(std::shared_ptr<Entity>)> shotImpactCallback;
    void handleEvent(SDL_Event&, bool flag);
};

#endif /* Player_hpp */
