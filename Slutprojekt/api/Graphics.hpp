//
//  Graphics.hpp
//  Slutprojekt
//
//  Created by Robin on 2016-11-27.
//  Copyright © 2016 Robin. All rights reserved.
//

#ifndef Graphics_hpp
#define Graphics_hpp

#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>

namespace engine{
class Graphics {
public:
    Graphics();
    ~Graphics();
    SDL_Renderer* getRenderer() const;
    void showWindow();
    void setWindowTitle(const std::string& title);
    void setWindowSize(const SDL_Rect& rect);
    bool loadLibraries();
    SDL_Rect getScreenSize();
    TTF_Font* getFont(int ptSize);
private:
    bool loadSDL();
    bool loadIMG();
    bool loadTTF();
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Rect windowRect;
    const std::string FONT_PATH = "SpaceShooterRedux/kenvector_future.ttf";    const std::string DEFAULT_WINDOW_TITLE = "Untitled";
};
    extern Graphics graphics;
}
#endif /* Graphics_hpp */
