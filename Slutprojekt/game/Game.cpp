//
//  Game.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-23.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "Game.hpp"
#include <string>
#include "MovableSprite.hpp"
#include "ScrollingBackgroundSprite.hpp"
#include "PlayerShot.hpp"
#include "Constants.hpp"
#include "Enemy.hpp"
#include <SDL2/SDL.h>
#include "EnemyShot.hpp"
#include "ShotImpact.hpp"
#include "TextFieldSprite.hpp"
#include "StaticSprite.hpp"
#include "LabelSprite.hpp"

using namespace std;
using namespace engine;
using namespace resourceConstants;
using namespace gameConstants;
using std::placeholders::_1;

int randomize(int max, int min = 1){
    return rand() % max + min;
}

Game::Game(): currentLevel(0), spawnTimer(0), player(nullptr),scoreBoard(nullptr), scoreBeforeLevelChange(100),scoreSinceLevelChange(0) {
    gameEngine = GameEngine::getInstance(TITLE, FPS);
    windowSize = gameEngine->getScreenSize();
    playerStartingPosition = {windowSize.w / 2 - PLAYERSHIP.w / 2, windowSize.h - PLAYERSHIP.h * 2};
    exitFunc = bind(&Game::exit, this);
    nextLevelCallback = bind(&Game::nextLevel, this);
    goToHomeScreenCallback = bind(&Game::goToHomeScreen, this);
    showTextFieldCallback = bind(&Game::showPlayerRegistration, this);
    updateScoreCallback = bind(&Game::updateScore, this, _1);
    spawnEntityCallback = bind(&Game::spawnEntity, this);
}

Game::~Game(){
    delete gameEngine;
}

int Game::getCurrentLevel() const{
    return currentLevel;
}

void Game::spawnEntity(){
    if(currentLevel != MAIN_MENU){
        int spawnEntity = rand() % 2 + 1;
        if(spawnEntity == 1){
            spawnMeteor();
        } else {
            spawnEnemy();
        }
    }
}

void Game::setup(){
    player = createPlayer();
    setupScenes();
    gameEngine->setLevel(currentLevel);
    bindKeys();
}

void Game::setupScenes(){
    shared_ptr<StaticSprite> mainMenuBg = StaticSprite::getInstance(BACKGROUND_STRINGS[0], windowSize, {windowSize.x, windowSize.y});
    shared_ptr<Scene> mainMenuScene = shared_ptr<Scene>(new Scene(mainMenuBg, windowSize));
    setupMainMenuItems();
    mainMenuScene->addSprite(titleLabel);
    mainMenuScene->addSprite(newGameBtn);
    mainMenuScene->addSprite(quitBtn);
    gameEngine->addLevel(0, mainMenuScene);
    for(int levelNumber = 1; levelNumber < BACKGROUND_STRINGS.size() ; levelNumber++){
        shared_ptr<ScrollingBackgroundSprite> bg = ScrollingBackgroundSprite::getInstance(BACKGROUND_STRINGS[levelNumber], windowSize, {windowSize.x, windowSize.y}, ScrollingDirection::VERTICAL);
        shared_ptr<Scene> scene = shared_ptr<Scene>(new Scene(bg, windowSize));
        scene->addSprite(scoreBoard);
        scene->addSprite(playerNameLbl);
        gameEngine->addLevel(levelNumber, scene);
    }
}

shared_ptr<TextFieldSprite> Game::createTextField(){
    SDL_Color blue = {54,187,245};
    return TextFieldSprite::getInstance(FONT_PATH, {windowSize.w / 2 - 120, static_cast<int>(windowSize.h * 0.405), 250,30}, {windowSize.w / 2 - 125 , static_cast<int>(windowSize.h * 0.40), 250, 30}, textColor, blue,PLAYER_NAME_TEXTFIELD_DEFAULT_TEXT);
}

void Game::setupMainMenuItems(){
    string titleString = "SPACESHOOTER";
    titleLabel = LabelSprite::getInstance(FONT_PATH, {windowSize.w / 2 - 150, static_cast<int>(windowSize.h * 0.2), 100,100}, 35, textColor, titleString);
    newGameBtn = createNewGameButton();
    quitBtn = createQuitButton();
    playerNameLbl = LabelSprite::getInstance(FONT_PATH, {windowSize.x, windowSize.y, 100,20}, 20, textColor, "Player: " + playerName);
    scoreBoard = createScoreboard("Score: ", {playerNameLbl->getCurrentPosition().x, playerNameLbl->getCurrentPosition().y + playerNameLbl->getRect().h});
    playerNameTextField = createTextField();
}

shared_ptr<ButtonSprite> Game::createNewGameButton(){
    SDL_Color color = {0,0,0,0};
    SDL_Color pressedColor = {220,220,220};
    string newGame = "New Game";
    return ButtonSprite::getInstance(SPRITESHEET, FONT_PATH, newGame,BLUE_BUTTON,20,{windowSize.w / 2 - BLUE_BUTTON.w / 2, windowSize.h / 2 - BLUE_BUTTON.h / 2}, color, pressedColor,showTextFieldCallback, nullptr);
}

shared_ptr<ButtonSprite> Game::createQuitButton(){
    SDL_Color color = {0,0,0,0};
    SDL_Color pressedColor = {220,220,220};
    string newGame = "Quit";
    return ButtonSprite::getInstance(SPRITESHEET, FONT_PATH, newGame,BLUE_BUTTON,20,{windowSize.w / 2 - BLUE_BUTTON.w / 2, windowSize.h / 2 + BLUE_BUTTON.h}, color, pressedColor,exitFunc, nullptr);
}

std::shared_ptr<Player> Game::createPlayer(){
    return shared_ptr<Player>(new Player(SPRITESHEET, windowSize, PLAYERSHIP, playerStartingPosition, PLAYER_ACCELERATION, PLAYER_SHOT_DELAY, PLAYER_SHOT, PLAYER_SHOT_IMPACT, goToHomeScreenCallback));
}

std::shared_ptr<Scoreboard> Game::createScoreboard(string&& defaultText, SDL_Point pos){
    return shared_ptr<Scoreboard>(new Scoreboard(FONT_PATH, {pos.x, pos.y, 50, 50}, 20, textColor, defaultText));
}

void Game::start(){
    gameEngine->run();
}

void Game::updateScore(shared_ptr<Entity> caller){
    int scoreToAdd = caller->getKillValue();
    scoreBoard->incrementScore(scoreToAdd);
    scoreSinceLevelChange += scoreToAdd;
    if(scoreSinceLevelChange >= scoreBeforeLevelChange){
        nextLevel();
        scoreSinceLevelChange = 0;
    }
}

void Game::spawnEnemy(){
    vector<SDL_Rect> possibleEnemies = enemies.at(currentLevel);
    unsigned long randomEnemyTexture =  possibleEnemies.size();
    SDL_Rect enemyRect = possibleEnemies.at(rand() % randomEnemyTexture);
    SDL_Point acceleration = {0, randomize(MAXIMUM_Y_ACCELERATION, 2)};
    SDL_Point startingPos = {randomize(windowSize.w - enemyRect.w), -enemyRect.h};
    gameEngine->addSprite(shared_ptr<Enemy>(new Enemy(SPRITESHEET, windowSize, enemyRect,ENEMY_SHOT, ENEMY_SHOT_IMPACT,startingPos, acceleration, true, ENEMY_SHOT_DELAY,updateScoreCallback)));
}

void Game::spawnMeteor(){
    unsigned long randomNr = meteorRectangles.size();
    SDL_Rect meteorRect = meteorRectangles.at(rand() % randomNr);
    SDL_Point acceleration = {randomize(MAXIMUM_X_ACCELERATION+MAXIMUM_X_ACCELERATION, - MAXIMUM_X_ACCELERATION), randomize(MAXIMUM_Y_ACCELERATION, 2)};
    int rotationSpeed = randomize(MAX_ROTATION_SPEED);
    gameEngine->addSprite(shared_ptr<Meteor>(new Meteor(SPRITESHEET, windowSize, meteorRect, { randomize(windowSize.w), -meteorRect.h},acceleration, rotationSpeed, updateScoreCallback)));
}

void Game::exit() {
    if(spawnTimer != 0){
        gameEngine->removeTimedCallback(spawnTimer);
    }
    gameEngine->terminate();
}

void Game::nextLevel(){
    if(currentLevel == MAIN_MENU){
        if(spawnTimer == 0){
            spawnTimer = gameEngine->installTimedCallback(ENTITY_SPAWN_RATE_MS, spawnEntityCallback);
        }
        if(playerNameTextField->getText() == "" || strcmp(playerNameTextField->getText().c_str(),PLAYER_NAME_TEXTFIELD_DEFAULT_TEXT.c_str()) == 0){
            return;
        }
        playerName = playerNameTextField->getText();
        playerNameLbl->setText(playerNameLbl->getText()+ playerName);
        scoreBoard->setRectangle({playerNameLbl->getRect().x, playerNameLbl->getRect().y + scoreBoard->getRect().h + 10});
        currentLevel++;
        gameEngine->clearCurrentScene();
        gameEngine->setLevel(currentLevel);
        gameEngine->addSprite(playerNameLbl);
        player = createPlayer();
        gameEngine->addSprite(scoreBoard);
        gameEngine->addSprite(player);
    } else if(currentLevel < BACKGROUND_STRINGS.size()-1){
        SDL_Point playerPos = player->getCurrentPosition();
        scoreSinceLevelChange = 0;
        currentLevel++;
        gameEngine->clearCurrentScene();
        gameEngine->setLevel(currentLevel);
        player = createPlayer();
        player->setPosition(playerPos);
        scoreBoard->setRectangle({playerNameLbl->getCurrentPosition().x, playerNameLbl->getCurrentPosition().y + playerNameLbl->getRect().h, scoreBoard->getRect().w});
        gameEngine->addSprite(scoreBoard);
        gameEngine->addSprite(player);
        gameEngine->addSprite(playerNameLbl);
    }
}

void Game::goToHomeScreen(){
    gameEngine->removeTimedCallback(spawnTimer);
    spawnTimer = 0;
    if(currentLevel != MAIN_MENU){
        currentLevel = MAIN_MENU;
        scoreSinceLevelChange = 0;
        scoreBoard->reset();
        playerNameTextField->reset();
        playerName = "";
        playerNameLbl->setText("Player: ");
        newGameBtn->setText("New Game");
        newGameBtn->setOnReleaseCallback(showTextFieldCallback);
        gameEngine->clearCurrentScene();
        gameEngine->setLevel(MAIN_MENU);
        gameEngine->addSprite(newGameBtn);
        gameEngine->addSprite(quitBtn);
        gameEngine->addSprite(titleLabel);
    }
}

void Game::showPlayerRegistration(){
    newGameBtn->setText("OK");
    newGameBtn->setOnReleaseCallback(nextLevelCallback);
    gameEngine->addSprite(playerNameTextField);
}

void Game::bindKeys(){
    gameEngine->installKeyCommand(SDLK_ESCAPE, bind(&Game::goToHomeScreen, this));
}
