//
//  Scoreboard.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-01.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "Scoreboard.hpp"
using namespace std;

Scoreboard::Scoreboard(const string& fontPath, SDL_Rect rectangle, int fontSize,SDL_Color& color, string& text): LabelSprite(fontPath, rectangle, fontSize, color, text), currentScore(0),text(text){
    setText(text + to_string(currentScore));
}

void Scoreboard::incrementScore(int scoreToAdd){
    currentScore += scoreToAdd;
    setText(text + to_string(currentScore));
}

void Scoreboard::reset(){
    currentScore = 0;
    setText(text + to_string(currentScore));
}

int Scoreboard::getCurrentScore() const {
    return currentScore;
}
