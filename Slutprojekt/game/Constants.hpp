//
//  ResourceConstants.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-04.
//  Copyright © 2016 Robin. All rights reserved.
//


#ifndef ResourceConstants_hpp
#define ResourceConstants_hpp

#include <SDL2/SDL.h>
#include <string>
#include <vector>

namespace gameConstants{
    const SDL_Rect WINDOW_RECT = {0,0,800,650};
    const SDL_Point PLAYER_ACCELERATION = {7,7};
    const SDL_Point PLAYER_SHOT_ACCELERATION = {0,-10};
    const SDL_Point ENEMY_SHOT_ACCELERATION = {0, 6};
    const int PLAYER_SHOT_DELAY = 15;
    const int ENTITY_SPAWN_RATE_MS = 1000;
    const int MAXIMUM_X_ACCELERATION = 2;
    const int MAXIMUM_Y_ACCELERATION = 2;
    const int ENEMY_SHOT_DELAY = 70;
    const int MAX_ROTATION_SPEED = 15;
    
    const int EXPLOSION_ANIMATION_SPEED = 3;
    
    const int MAIN_MENU = 0;
    
}

namespace resourceConstants {
    const SDL_Rect PLAYERSHIP = {237, 377, 99, 75};
    const SDL_Rect BLUE_BUTTON = {0,78,222,39};
    
    //shots
    const SDL_Rect PLAYER_SHOT = {849,310,9,54};

    const SDL_Rect ENEMY_SHOT = {856,812,9,57};
    
    const SDL_Rect PLAYER_SHOT_IMPACT = {192,240,48,46};
    const SDL_Rect ENEMY_SHOT_IMPACT = {580,661,48,46};
    

    //meteors
    const SDL_Rect BIG_BROWN_METEOR_1 = {224, 664, 101, 84};
    const SDL_Rect BIG_BROWN_METEOR_2 = {0,520,120,98};
    const SDL_Rect MEDIUM_BROWN_METEOR_1 = {651,447,43,43};
    const SDL_Rect MEDIUM_BROWN_METEOR_2 = {237,452,45,40};
    const SDL_Rect SMALL_BROWN_METEOR = {406,234,28,28};
    
    //enemyUFOs
    const SDL_Rect BLUE_UFO = {444, 91, 91,91};
    const SDL_Rect GREEN_UFO = {434, 234, 91,91};
    const SDL_Rect RED_UFO = {444,0,91,91};
    
    //enemyShips
    const SDL_Rect BLACK_ENEMY_SHIP = { 423, 728, 93, 84};
    const SDL_Rect BLUE_ENEMY_SHIP = {425, 468, 93, 84};
    const SDL_Rect GREEN_ENEMY_SHIP = {133,412,104,84};
    const SDL_Rect RED_ENEMY_SHIP = {425, 384, 93,84};
    

    const std::vector<SDL_Rect> lvl1Enemies = {BLACK_ENEMY_SHIP};
    const std::vector<SDL_Rect> lvl2Enemies = {BLUE_ENEMY_SHIP, BLUE_UFO};
    const std::vector<SDL_Rect> lvl3Enemies = {RED_ENEMY_SHIP, RED_UFO};
    
    const std::unordered_map<int,std::vector<SDL_Rect>> enemies = { {1, lvl1Enemies}, {2, lvl2Enemies}, {3, lvl3Enemies}};
    std::vector<SDL_Rect> meteorRectangles = {BIG_BROWN_METEOR_1, BIG_BROWN_METEOR_2, MEDIUM_BROWN_METEOR_1, MEDIUM_BROWN_METEOR_2, SMALL_BROWN_METEOR};

    
    const std::string TITLE = "SpaceShooter :-)";
    const std::string SPRITESHEET = "resources/Spritesheet/sheet.png";
    const std::vector<const std::string> BACKGROUND_STRINGS = {"resources/Backgrounds/startscreen.png", "resources/Backgrounds/lvl1.png", "resources/Backgrounds/lvl2.png", "resources/Backgrounds/lvl3.png"  };
    const std::string FONT_PATH = "resources/kenvector_future.ttf";
    const SDL_Point EXPLOSION_SIZE = {130,133};
    
}
#endif /* Constants_hpp */


