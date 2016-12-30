//
//  ButtonSprite.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-12-05.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef ButtonSprite_hpp
#define ButtonSprite_hpp

#include "Labeled.hpp"
namespace engine {
class ButtonSprite: public Labeled {
public:
    void tick(GameEngine*) override;
    void loadResources(ResourceManager&) override;
    void handleEvent(SDL_Event&) override;
    static std::shared_ptr<ButtonSprite> getInstance(const std::string&, const std::string&, std::string&, SDL_Rect, int,SDL_Point,SDL_Color, SDL_Color,std::function<void()> onReleaseCallback, std::function<void()> onPressedCallback);
    void setOnReleaseCallback(std::function<void()>);
    template <typename T>
    void setOnPressedCallback(std::function<T()>);
    void setText(std::string&& newText);
protected:
    void draw() override;
    ButtonSprite(const std::string&, const std::string&, std::string&, SDL_Rect, int,SDL_Point,SDL_Color, SDL_Color,std::function<void()> onReleaseCallback, std::function<void()> onPressedCallback);
private:
    bool pressed;
    SDL_Texture* buttonTexture;
    std::string buttonTexturePath;
    SDL_Color colorOnPress;
    SDL_Rect rect;
    std::function<void()> onReleaseCallback;
    std::function<void()> onPressedCallback;
    const ButtonSprite& operator=(const ButtonSprite& other) = delete;
    ButtonSprite(const ButtonSprite& other) = delete;
};
}

#endif /* ButtonSprite_hpp */
