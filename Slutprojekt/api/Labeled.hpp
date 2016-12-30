//
//  Labeled.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-01.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef Labeled_hpp
#define Labeled_hpp

#include <SDL2_ttf/SDL_ttf.h>
#include "Sprite.hpp"

namespace engine {
    class Labeled: public Sprite {
    public:
        ~Labeled();
        std::string getText() const;
        void draw();
        void setText(const std::string& newText);
        void loadResources(ResourceManager& resourceManager);
        
    protected:
        Labeled(const std::string& fontPath, SDL_Rect, int, SDL_Color&, std::string text = "");
        const SDL_Color getTextColor() const { return textColor; };
        void setTextColor(const SDL_Color& color);
    private:
        std::string text;
        TTF_Font* font;
        int fontSize;
        SDL_Color textColor;
    };
}

#endif /* Labeled_hpp */
