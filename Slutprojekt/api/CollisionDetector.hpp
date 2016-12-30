//
//  CollisionHandler.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-30.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef CollisionDetector_hpp
#define CollisionDetector_hpp

#include <list>

namespace engine {
    class Sprite;
    class CollisionDetector {
    public:
        void checkCollisions(std::list<std::shared_ptr<Sprite>>& sprites);
    private:
        bool hasCollided(std::shared_ptr<Sprite> first, std::shared_ptr<Sprite> second);
    };
}
#endif /* CollisionHandler_hpp */
