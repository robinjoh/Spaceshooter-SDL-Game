//
//  LabelSprite.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-13.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef LabelSprite_hpp
#define LabelSprite_hpp

#include "Labeled.hpp"
namespace engine {
class LabelSprite: public Labeled {
    public:
    void tick(GameEngine*);
    static std::shared_ptr<LabelSprite> getInstance(const std::string& fontPath, SDL_Rect, int, SDL_Color&, std::string text = "");
    protected:
    void draw();
    LabelSprite(const std::string&, SDL_Rect, int font, SDL_Color, std::string);
    private:
    const LabelSprite& operator=(const LabelSprite& other) = delete;
    LabelSprite(const LabelSprite& other) = delete;
};

}

#endif /* LabelSprite_hpp */
