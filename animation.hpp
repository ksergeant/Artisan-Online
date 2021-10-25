#ifndef ANIMATION_H // include guard
#define ANIMATION_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class animation
{
    public:
        animation(string nom);
        ~animation();
        //vector <shared_ptr<SDL_Rect> > listeRect; // Vecteur de rectangle (chaque rectangle correspond à une image)
        vector <SDL_Rect> listeRectAni;
        void getRect();
        //void setRect(shared_ptr<SDL_Rect> ptr);
        void setRect(SDL_Rect ptr);
    private:
        string nom;
        
};

#endif