//
//  Explodable.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "Explodable.hpp"
#include "AnimatedSprite.hpp"
using namespace std;


std::vector<SDL_Rect> getRects(int nrOfRows, int nrOfColumns, SDL_Point sizeOfEachRect){
    std::vector<SDL_Rect> vec;
    for(int i = 0; i < nrOfRows; i++){
        for(int j = 0; j < nrOfColumns; j++){
            SDL_Rect rect = {j * sizeOfEachRect.x, i * sizeOfEachRect.y, sizeOfEachRect.x , sizeOfEachRect.y};
            vec.push_back(rect);
        }
    }
    return vec;
}

bool Explodable::shouldExplode() const {
    return shouldPerformExplosion;
}

void Explodable::setShouldExplode(bool b){
    shouldPerformExplosion = b;
}

Explodable::Explodable(function<void()> explosionFinishedCallback): explosionFinishedCallback(explosionFinishedCallback), shouldPerformExplosion(false){
    explosionRects = getRects(4, 4, EXPLOSION_SIZE);
}

void Explodable::explode(engine::GameEngine* engine){
    engine->addSprite(engine::AnimatedSprite::getInstance(explosionSheetPath, getRect(), getCurrentPosition(), explosionRects, 1, 3, explosionFinishedCallback));
}
