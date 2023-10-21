#ifndef SPRITEMANAGER_H // include guard
#define SPRITEMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "sprite.hpp"
#include <vector>

using namespace std;

class spriteManager
{
    public:
        spriteManager();
        ~spriteManager();
        vector <shared_ptr<sprite> > listeSprites;
        void addSprite(string nom, int x, int y, double scaleX, double scaleY, string path_image);
        SDL_Texture * setSpriteSheet(SDL_Renderer *renderer, SDL_Texture * textureTempo, string nomSprite, string path_image, int tileWidth, int tileHeight, int decalX, int decalY, int debutX, int debutY, int pscaleX, int pscaleY);
        void loadAllTexture(SDL_Renderer *renderer, SDL_Texture * p_texture);
        void update(SDL_Renderer *renderer);
        void launchModeDebug();
        
    private:
        
};

#endif