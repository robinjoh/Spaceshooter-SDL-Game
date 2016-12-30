//
//  TextSprite.cpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-17.
//  Copyright © 2016 Robin. All rights reserved.
//

#include "TextFieldSprite.hpp"
#include "Graphics.hpp"

using namespace std;
namespace engine {
    
    TextFieldSprite::TextFieldSprite(const std::string& texturePath, SDL_Rect rectangle, SDL_Rect textBox,SDL_Color& textColor,SDL_Color& textBoxColor,const string& defaultText): Labeled(texturePath, rectangle, 20, textColor,defaultText), editing(false),defaultText(defaultText), textBoxColor(textBoxColor), textBox(textBox){
      
    }
    
    void TextFieldSprite::tick(GameEngine*engine){
        setCurrentTick(getCurrentTick()+1);
    }
    
    void TextFieldSprite::draw(){
        SDL_Rect rect = getRect();
        rect.x = rect.x + rect.w;
        SDL_Color textColor = getTextColor();
        SDL_SetRenderDrawColor(graphics.getRenderer(), textBoxColor.r, textBoxColor.g, textBoxColor.b, textBoxColor.a);
        SDL_RenderFillRect(graphics.getRenderer(), &textBox);
        SDL_SetRenderDrawColor(graphics.getRenderer(), textColor.r, textColor.g, textColor.b, textColor.a);
        if(getText() != ""){
            Labeled::draw();
        }
        if(editing){
            if(getCurrentTick() < CARET_BLINKING_INTERVAL){
                if(getText() == ""){
                    SDL_RenderDrawLine(graphics.getRenderer(), textBox.x + 2, getRect().y, textBox.x + 2 , textBox.y + getRect().h);
                } else {
                SDL_RenderDrawLine(graphics.getRenderer(), getRect().x + getRect().w, getRect().y, getRect().x + getRect().w,getRect().y + getRect().h);
                }
            } else if(getCurrentTick() >= CARET_BLINKING_INTERVAL * 2){
                setCurrentTick(0);
            }
        }
    }
    
    void TextFieldSprite::reset(){
        setText(defaultText);
    }
    
    shared_ptr<TextFieldSprite> TextFieldSprite::getInstance(const string& texturePath, SDL_Rect rect, SDL_Rect textBox,SDL_Color& textColor, SDL_Color& textBoxColor, const string& defaultText){
        return shared_ptr<TextFieldSprite>(new TextFieldSprite(texturePath, rect, textBox,textColor, textBoxColor,defaultText));
    }
    
    void TextFieldSprite::handleEvent(SDL_Event &event){
        SDL_Point click = { event.button.x, event.button.y};
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                if(SDL_PointInRect(&click, &textBox)){
                    if(!editing){
                        setText("");
                    }
                    SDL_StartTextInput();
                    editing = true;
                } else {
                    editing = false;
                    SDL_StopTextInput();
                }
                break;
            case SDL_KEYDOWN:
                if(editing && event.key.keysym.sym == SDLK_BACKSPACE && getText().length() > 0){
                    std::string s = getText();
                    s.pop_back();
                    setText(s);
                } else if(editing && event.key.keysym.sym == SDLK_RETURN){
                    editing = false;
                    SDL_StopTextInput();
                }
                break;
            case SDL_TEXTINPUT:
                if(editing && getRect().x + getRect().w * 1.1 < textBox.x + textBox.w){
                    setText(getText() + event.text.text);
                }
                break;
        }
    }
    
}



