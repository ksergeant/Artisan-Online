#include "player.hpp"

player::player(string nom, int x, int y)
{
    this->nom = nom;
    this->x = x;
    this->y = y;
    this->scaleX = 1;
    this->scaleY = 1;
}

player::~player()
{
    SDL_DestroyTexture(texture);
}



// Découpe la spritesheet en SDL_Rect et remplir le vector liste des rectangles du personnage
void player::setSpriteSheet(SDL_Renderer *renderer, string path_image, int tileWidth, int tileHeight, int decalX, int decalY,
                            int debutX, int debutY)
{
    this->path_image = path_image;
    int dimensionTempoW = 0;
    int dimensionTempoH = 0;

    texture = IMG_LoadTexture(renderer, path_image.c_str());
    if (texture == NULL)
    {
        printf("Unable to create texture from %s Error: %s\n", path_image.c_str(), IMG_GetError());     
    }

    else 
    {
        SDL_QueryTexture(texture, NULL, NULL, &dimensionTempoW, &dimensionTempoH); // récuperation des dimensions de la texture

        // 384 × 256
        
        int nombreImagesLargeur = dimensionTempoW / tileWidth; // Calcul du nombre d'images en largeur 
        int nombreImagesHauteur = dimensionTempoH / tileHeight; // Calcul du nombres d'images en hauteur

        if (debutX !=0)
        {

        }

        if (debutY !=0)
        {
            
        }
        
        int decalTempoY = 0;
        for(int i = 0; i < nombreImagesHauteur; i++)
        {
            int decalTempoX = 0;
            for(int i2 = 0; i2 < nombreImagesLargeur; i2++)
            {
                SDL_Rect rectempo = {decalTempoX, decalTempoY, tileWidth, tileHeight};
                
                SDL_Rect ptr=rectempo;
                this->listeRect.push_back(ptr);
                
                decalTempoX = decalTempoX + tileWidth;
                
            }

            decalTempoY = decalTempoY + tileHeight;
        }

        cout << "dimension_w -> " << dimensionTempoW <<endl;
        cout << "dimension_h -> " << dimensionTempoH <<endl;
        SDL_Rect rectexture2 = {xRect, yRect, (dimension_w * scaleX), (dimension_h * scaleY)}; // Rectangle pour afficher l'image
        //cout << "ScaleX: " << scaleX << " ScaleY: " << scaleY <<endl; 
 
       //rectangle = rectexture2; 
        cout << "Chargement de la texture du sprite: " << nom << " Reussi"<< endl;
    }

}

// Formate les SDL_Rect de la listeRect du perso pour les transformer en Objet animation 
void player::recToAnimation(vector<int> arrIndex, string nomAnimation)
{
    cout << "test 1" <<endl;
    array <int,3> arrTest1={0,1,2};
    array <int,3> arrTest2={12,13,14};
    array <int,3> arrTest3={24,25,26};
    array <int,3> arrTest4={36,37,38};

    animation animTempo(nomAnimation);
    cout << "test 2" <<endl;
    shared_ptr <animation> animationTempo(make_shared<animation>(animTempo));

    cout << "test 3" <<endl;
    // Tant qu'il y a des index on les ajoute dans l'animation
    int tailleIndex = arrIndex.size();
    cout << "taille index : "  <<tailleIndex<<endl;
    for(int i = 0; i < tailleIndex; i++)
    {    
        SDL_Rect rectempo = {0, 0, 0, 0};
        SDL_Rect ptr = rectempo;
        ptr = listeRect[arrIndex[i]];
        animationTempo->setRect(ptr); 
        cout << "test 4" <<endl;     
    }

    cout << "test 5" <<endl;
    this->listeAnimation.push_back(animationTempo);
    cout << "test 6" <<endl;
}

void player::getAnimation()
{


}

void player::LoadTexture(SDL_Renderer *renderer)
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
        SDL_Rect rectexture2 = {xRect, yRect, (dimension_w * scaleX), (dimension_h * scaleY)}; // Rectangle pour afficher l'image
        //rectangle = rectexture2; 
        cout << "Chargement de la texture du sprite: " << nom << " Reussi"<< endl;
    }
    
}

 void player::move(int direction, int pixelDeplacement)
 {
     switch(direction)
     {
         // LEFT
        case 0:
            this->x -= pixelDeplacement;
            break;

        // RIGHT
        case 1:
            this->x += pixelDeplacement;
            break;

        // UP
        case 2:
            this->y -= pixelDeplacement;
            break;

        // DOWN
        case 3:
            this->y += pixelDeplacement;
            break;

        default:
            break;
     }

 }
