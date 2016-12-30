//
//  Entity.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-07.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "Sprite.hpp"

class Entity: virtual public engine::Sprite {
public:
    ~Entity() = 0;
    Entity(int life, int killValue = 0);
    void setLife(int newLife);
    int getLife() const;
    bool shouldKill() const;
    int getKillValue()const;
protected:
    void setKill(bool);
private:
    int killValue;
    int life;
    bool killThis;
};
#endif /* Entity_hpp */
