#ifndef SPRITE_H // include guard
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

using namespace std;

class sprite
{
    public:
        sprite(string nom, int x, int y, double scaleX, double scaleY, string path_image);
        ~sprite();
        void LoadTexture(SDL_Renderer *renderer);
        SDL_Texture * texture;
        SDL_Rect rectangle;
        int xRect, yRect, dimension_w, dimension_h;
        bool modeDebug;
        string nom;

    private:
        //int xRect, yRect, dimension_w, dimension_h;
        double scaleX, scaleY;   
        string path_image;
        
};

#endif