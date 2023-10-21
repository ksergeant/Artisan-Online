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
        sprite();
        sprite(string nom, int x, int y, double scaleX, double scaleY, string path_image);
        sprite(string nom, int x, int y, double scaleX, double scaleY, string path_image, SDL_Rect rectangleSrc, SDL_Rect rectangleDst);
        ~sprite();
        void LoadTexture(SDL_Renderer *renderer);
        void setTexture(SDL_Texture * p_texture);
        int type;
        SDL_Texture * texture;
        SDL_Rect rectangleSrc;
        SDL_Rect rectangleDst;
        int xRect, yRect, dimension_w, dimension_h;
        double scaleX, scaleY; 
        string path_image;
        bool modeDebug;
        string nom;
 

    private:
        //int xRect, yRect, dimension_w, dimension_h;
          
        
        
};

#endif