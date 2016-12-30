//
//  CollisionHandler.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-30.
//  Copyright © 2016 Robin. All rights reserved.
//
#include "Sprite.hpp"
#include "CollisionDetector.hpp"

using namespace std;

namespace engine {
    
    void CollisionDetector::checkCollisions(list<shared_ptr<Sprite>>& sprites){
        for(auto first: sprites) {
            for(auto second : sprites) {
                if(first->isCollidable() && first != second && hasCollided(first, second)){
                    first->didCollideWith(second);
                }
            }
        }
    }
    
    bool CollisionDetector::hasCollided(shared_ptr<Sprite> first,
                                       shared_ptr<Sprite> second){
        SDL_Point firstPos = first->getCurrentPosition();
        SDL_Point secondPos = second->getCurrentPosition();
        SDL_Rect firstRect = first->getRect();
        firstRect.x = firstPos.x;
        firstRect.y = firstPos.y;
        SDL_Rect secondRect = second->getRect();
        secondRect.x = secondPos.x;
        secondRect.y = secondPos.y;
        SDL_Rect intersection;
        SDL_IntersectRect(&firstRect, &secondRect, &intersection);
        
        return SDL_HasIntersection(&firstRect, &secondRect);
    }
    
    
}
