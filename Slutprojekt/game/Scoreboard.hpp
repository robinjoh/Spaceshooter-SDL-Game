//
//  Scoreboard.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-01.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef Scoreboard_hpp
#define Scoreboard_hpp

#include "LabelSprite.hpp"

class Scoreboard: public engine::LabelSprite {
public:
    Scoreboard(const std::string& fontPath, SDL_Rect rectangle, int fontSize,SDL_Color& color, std::string& text);
    void incrementScore(int scoreToAdd);
    int getCurrentScore() const;
    void reset();
private:
    int currentScore;
    std::string text;
};

#endif /* Scoreboard_hpp */
