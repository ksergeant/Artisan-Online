#include "sprite.hpp"

sprite::sprite(string nom, int x, int y, double scaleX, double scaleY, string path_image)
{
    this->nom = nom;
    this->xRect = x;
    this->yRect = y;
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->path_image = path_image;    
    this->modeDebug = false;
}

sprite::~sprite()
{
    SDL_DestroyTexture(texture);
}
void sprite::LoadTexture(SDL_Renderer *renderer)
{
   // SDL_Texture *textureTemp = NULL;

    texture = IMG_LoadTexture(renderer, path_image.c_str());
    if (texture == NULL)
    {
        printf("Unable to create texture from %s Error: %s\n", path_image.c_str(), IMG_GetError());     
    }

    else 
    {
        SDL_QueryTexture(texture, NULL, NULL, &dimension_w, &dimension_h); // récuperation des dimensions de la texture
        dimension_w = dimension_w * scaleX;
        dimension_h = dimension_h * scaleY;
        SDL_Rect rectexture2 = {xRect, yRect, dimension_w, dimension_h}; // Rectangle pour afficher l'image
        rectangle = rectexture2; 
        cout << "Chargement de la texture du sprite: " << nom << " Reussi"<< endl;
    }
    
}