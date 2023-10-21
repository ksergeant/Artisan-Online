#include "../include/sprite.hpp"

sprite::sprite()
{
   
}

sprite::sprite(string nom, int x, int y, double scaleX, double scaleY, string path_image)
{
    this->nom = nom;
    this->xRect = x;
    this->yRect = y;
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->path_image = path_image;    
    this->modeDebug = false;
    this->type = 1;
    this->texture = nullptr;
}

// sprite venant de tilesheet on passe de le type à 2
sprite::sprite(string nom, int x, int y, double scaleX, double scaleY, string path_image, SDL_Rect rectangleSrc, SDL_Rect rectangleDst)
{
    this->nom = nom;
    this->xRect = x;
    this->yRect = y;
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->path_image = path_image;    
    this->modeDebug = false;
    this->type = 2;
    this->rectangleSrc = rectangleSrc;
    this->rectangleDst = rectangleDst;
}
sprite::~sprite()
{
    //cout << "Destroy la texture du sprite " << nom <<endl;
    SDL_DestroyTexture(texture);
}
void sprite::LoadTexture(SDL_Renderer *renderer)
{
   // SDL_Texture *textureTemp = NULL;

    texture = IMG_LoadTexture(renderer, path_image.c_str());
    if (texture == nullptr)
    {
        printf("Unable to create texture from %s Error: %s\n", path_image.c_str(), IMG_GetError());     
    }

    else 
    {
        SDL_QueryTexture(texture, NULL, NULL, &dimension_w, &dimension_h); // récuperation des dimensions de la texture
        dimension_w = dimension_w * scaleX;
        dimension_h = dimension_h * scaleY;
        SDL_Rect rectexture2 = {xRect, yRect, dimension_w, dimension_h}; // Rectangle pour afficher l'image
        rectangleSrc = rectexture2; 
        cout << "Chargement de la texture du sprite: " << nom << " Reussi"<< endl;
    }
    
}

void sprite::setTexture(SDL_Texture *p_texture)
{

this->texture = p_texture;
}