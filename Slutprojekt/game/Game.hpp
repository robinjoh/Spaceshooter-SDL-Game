//
//  Game.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-23.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "Player.hpp"
#include "Meteor.hpp"
#include "Entity.hpp"
#include "Scoreboard.hpp"
#include "LabelSprite.hpp"
#include "TextFieldSprite.hpp"
#include "ButtonSprite.hpp"
#include "GameEngine.hpp"

class Game {
public:
    Game();
    ~Game();
    void setup();
    void start();
    void spawnMeteor();
    void spawnEnemy();
    void updateScore(std::shared_ptr<Entity> caller);
    void exit();
    void goToHomeScreen();
    int getCurrentLevel() const;
    void nextLevel();
    void showPlayerRegistration();
private:
    engine::GameEngine* gameEngine;
    const int FPS = 70;
    int currentLevel;
    int scoreBeforeLevelChange;
    int scoreSinceLevelChange;
    const std::string PLAYER_NAME_TEXTFIELD_DEFAULT_TEXT = "Player name";
    SDL_Color textColor = {255,255,255,255};
    std::shared_ptr<Scoreboard> scoreBoard;
    std::string playerName;
    std::shared_ptr<Player> player;
    std::shared_ptr<engine::ButtonSprite> quitBtn;
    std::shared_ptr<engine::ButtonSprite> newGameBtn;
    std::shared_ptr<engine::LabelSprite> playerNameLbl;
    std::shared_ptr<engine::TextFieldSprite>playerNameTextField;
    std::shared_ptr<engine::LabelSprite> titleLabel;
    SDL_Rect windowSize;
    SDL_Point playerStartingPosition;
    SDL_TimerID spawnTimer;
    std::function<void()> exitFunc;
    std::function<void()> goToHomeScreenCallback;
    std::function<void()> nextLevelCallback;
    std::function<void()> showTextFieldCallback;
    std::function<void(std::shared_ptr<Entity>)> updateScoreCallback;
    std::function<void()> spawnEntityCallback;
    void bindKeys();
    std::shared_ptr<Player> createPlayer();
    std::shared_ptr<engine::TextFieldSprite> createTextField();
    std::shared_ptr<Scoreboard> createScoreboard(std::string&& defaultText, SDL_Point);
    std::shared_ptr<engine::ButtonSprite> createNewGameButton();
    std::shared_ptr<engine::ButtonSprite> createQuitButton();
    std::shared_ptr<engine::ButtonSprite> createOkButton(SDL_Point);
    void spawnEntity();
    void setupMainMenuItems();
    void setupScenes();
};

#endif /* Game_hpp */
