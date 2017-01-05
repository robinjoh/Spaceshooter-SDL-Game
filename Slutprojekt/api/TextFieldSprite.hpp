//
//  TextSprite.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef TextFieldSprite_hpp
#define TextFieldSprite_hpp

#include "Labeled.hpp"

namespace engine {
    class TextFieldSprite: public Labeled {
    public:
        void handleEvent(SDL_Event&);
        void draw();
        void tick(GameEngine*);
        static std::shared_ptr<TextFieldSprite> getInstance(const std::string&, SDL_Rect, SDL_Rect,SDL_Color&,SDL_Color&, const std::string&);
        void reset();
    protected:
        TextFieldSprite(const std::string& texturePath, SDL_Rect rectangle,SDL_Rect textBox, SDL_Color&, SDL_Color&, const std::string&);
    private:
        bool editing;
        const std::string defaultText;
        const int CARET_BLINKING_INTERVAL = 50;
        SDL_Rect textBox;
        SDL_Color textBoxColor;
    };
}

#endif /* TextSprite_hpp */
