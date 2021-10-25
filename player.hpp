#ifndef PLAYER_H // include guard
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <vector>
#include "animation.hpp"
#include <array>

using namespace std;

class player
{
    public:
        player(string nom, int x, int y);
        ~player();
        void LoadTexture(SDL_Renderer *renderer);
        void setSpriteSheet(SDL_Renderer *renderer, string path_image, int tileWidth, int tileHeight, int decalX, int decalY, int debutX, int debutY);
        SDL_Texture * texture; // SpriteSheet 
        vector <SDL_Rect> listeRect; // Vecteur de rectangle (chaque rectangle correspond à une image)
        vector <shared_ptr<animation> > listeAnimation;
        void recToAnimation(array<int,1000>, string nomAnimation);
        void getAnimation();

    private:
        int x;
        int y;
        int xRect, yRect, dimension_w, dimension_h;
        double scaleX, scaleY;   
        string path_image;
        string nom;
        
};

#endif