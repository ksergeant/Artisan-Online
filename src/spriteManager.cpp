#include "../include/spriteManager.hpp"

spriteManager::spriteManager()
{

}

spriteManager::~spriteManager()
{

}

void spriteManager::addSprite(string nom, int x, int y, double scaleX, double scaleY, string path_image)
{
    sprite spriteTempo(nom, x, y, scaleX, scaleY, path_image);
    shared_ptr<sprite> ptr(make_shared<sprite>(spriteTempo));
    this->listeSprites.push_back(ptr);
}

// Découpe la spritesheet en SDL_Rect et remplir le vector liste des rectangles du personnage
SDL_Texture * spriteManager::setSpriteSheet(SDL_Renderer *renderer, SDL_Texture * textureTempo, string nomSprite, string path_image, int tileWidth, int tileHeight, int decalX, int decalY,
                            int debutX, int debutY, int pscaleX, int pscaleY)
{
    int compteurSprite = 0;
    string path_imageTempo = path_image;
    int dimensionTempoW = 0;
    int dimensionTempoH = 0;
    int nombreSprite = 1;
    int x = 0;
    int y = 0;
    int scaleX = pscaleX;
    int scaleY = pscaleY;
    textureTempo = IMG_LoadTexture(renderer, path_imageTempo.c_str());
    if (textureTempo == nullptr)
    {
        printf("Unable to create texture from %s Error: %s\n", path_imageTempo.c_str(), IMG_GetError());     
    }

    else 
    {
        if(SDL_QueryTexture(textureTempo, NULL, NULL, &dimensionTempoW, &dimensionTempoH)!=0) // récuperation des dimensions de la texture
        {
            cout <<"Premier test ";
            cout << SDL_GetError() <<endl;
        }
        // 384 × 256
        
        int nombreImagesLargeur = dimensionTempoW / tileWidth; // Calcul du nombre d'images en largeur 
        int nombreImagesHauteur = dimensionTempoH / tileHeight; // Calcul du nombres d'images en hauteur
  
        int decalTempoY = 0;
        for(int i = 0; i < nombreImagesHauteur; i++)
        {
            int decalTempoX = 0;
            x = 0;
            for(int i2 = 0; i2 < nombreImagesLargeur; i2++)
            {
                if(compteurSprite == 54 || compteurSprite == 55 || compteurSprite == 56 || compteurSprite == 57
                || compteurSprite == 58 || compteurSprite == 59 || compteurSprite == 66 || compteurSprite == 67
                || compteurSprite == 68 || compteurSprite == 69 || compteurSprite == 70 || compteurSprite == 71
                || compteurSprite == 76 || compteurSprite == 77 || compteurSprite == 78 || compteurSprite == 79
                || compteurSprite == 80 || compteurSprite == 81 || compteurSprite == 80 || compteurSprite == 81
                || compteurSprite == 86 || compteurSprite == 87 || compteurSprite == 88 || compteurSprite == 89
                || compteurSprite == 90 || compteurSprite == 91 
                
                )
                {
                   compteurSprite = compteurSprite +1;
                }
                else
                {
                    x=x+64;
                    int dimension_w = tileWidth * scaleX;
                    int dimension_h = tileHeight * scaleY;
                    SDL_Rect rectempoSrc = {decalTempoX, decalTempoY, tileWidth, tileHeight};
                    SDL_Rect rectempoDst = {x, y, dimension_w, dimension_h};
                    SDL_Rect ptr=rectempoSrc;
                    SDL_Rect ptr2=rectempoDst;
                    
                    decalTempoX = decalTempoX + tileWidth;
                    string posImgHaut =  to_string(i);
                    string posImgLarg =  to_string(i2);
                    string nomSpriteTempo = nomSprite + "_H_" + posImgHaut + "_L_" + posImgLarg;
                    //string nom, int x, int y, double scaleX, double scaleY, string path_image, SDL_Texture * texture, SDL_Rect rectangle
                    
                    sprite spriteTempo(nomSpriteTempo, x, y, scaleX, scaleY, path_image, ptr, ptr2);
                    shared_ptr<sprite> ptr3(make_shared<sprite>(spriteTempo));
                    this->listeSprites.push_back(ptr3);
                    compteurSprite = compteurSprite +1;
                }
                
            }

            decalTempoY = decalTempoY + tileHeight;
            y = y+64;
        }
    }

    return textureTempo;
}

void spriteManager::loadAllTexture(SDL_Renderer *renderer, SDL_Texture *p_texture)
{
    if (listeSprites.size() > 0)
    {
        for (int i = 0; i < listeSprites.size(); i++)
        {
            if (listeSprites[i]->type ==1)
            {
                listeSprites[i]->LoadTexture(renderer);
            }

            if (listeSprites[i]->type == 2)
            {
                if(p_texture !=nullptr)
                {
                    listeSprites[i]->setTexture(p_texture);
                   
                }     
            }
        }
    }

    else 
    {
        cout << "Aucun sprite dans le manager de sprite" <<endl;
    }

}

void spriteManager::update(SDL_Renderer *renderer)
{
     SDL_RenderClear(renderer);
     if (listeSprites.size() > 0)
     {
        for (int i = 0; i < listeSprites.size(); i++)
        {
            // si le 3 parametres est null, c'est l'intégralité de la texture qui va être copié
            //renderer, the rendering context
            //texture, the source texture
            //srcrect, the source SDL_Rect structure or NULL for the entire texture
            //dstrect, the destination SDL_Rect structure or NULL for the entire rendering target; the texture will be stretched to fill the given rectangle
            
            // si le sprite est de type tileSheet(2) on change la méthode d'affichage

            if (listeSprites[i]->type == 2)
            {
              if(SDL_RenderCopy(renderer, listeSprites[i]->texture, &listeSprites[i]->rectangleSrc, &listeSprites[i]->rectangleDst)!=0)
                {
                    cout <<"Deuxieme test ";
                    cout << SDL_GetError() <<endl;
                }     
            }
            else
            {
                SDL_RenderCopy(renderer, listeSprites[i]->texture, NULL, &listeSprites[i]->rectangleSrc);
            }
            
            if(listeSprites[i]->modeDebug==true)
            {
                // sprite de spriteSheet
                if (listeSprites[i]->type == 2)
                {
                    int xTempo = listeSprites[i]->rectangleDst.x;
                    int yTempo = listeSprites[i]->rectangleDst.y;
                    int widhTempo = listeSprites[i]->rectangleDst.w;
                    int heightTempo = listeSprites[i]->rectangleDst.h;

                    SDL_RenderDrawPoint(renderer, xTempo, yTempo);
                    SDL_RenderDrawPoint(renderer, xTempo + widhTempo, yTempo);
                    SDL_RenderDrawPoint(renderer, xTempo + widhTempo, yTempo + heightTempo);
                    SDL_RenderDrawPoint(renderer, xTempo, yTempo + heightTempo);
                    SDL_RenderDrawPoint(renderer, xTempo + widhTempo, yTempo + heightTempo);

                    SDL_RenderDrawLine(renderer, xTempo, yTempo, xTempo + widhTempo, yTempo);
                    SDL_RenderDrawLine(renderer, xTempo, yTempo, xTempo, yTempo + heightTempo);
                    SDL_RenderDrawLine(renderer, xTempo + widhTempo, yTempo, xTempo + widhTempo, yTempo + heightTempo);
                    SDL_RenderDrawLine(renderer, xTempo + widhTempo, yTempo + heightTempo, xTempo, yTempo + heightTempo);
                    SDL_RenderDrawLine(renderer, xTempo + widhTempo, yTempo + heightTempo, xTempo, yTempo + heightTempo);

                    // Diagonale
                    SDL_RenderDrawLine(renderer, xTempo, yTempo, xTempo + widhTempo, yTempo + heightTempo);
                    SDL_RenderDrawLine(renderer, xTempo + widhTempo, yTempo, xTempo, yTempo + heightTempo);

                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // rouge
                }
                else
                {
                    int xTempo = listeSprites[i]->xRect;
                    int yTempo = listeSprites[i]->yRect;
                    int widhTempo = listeSprites[i]->dimension_w;
                    int heightTempo = listeSprites[i]->dimension_h;
                
                    SDL_RenderDrawPoint(renderer, xTempo, yTempo);
                    SDL_RenderDrawPoint(renderer, xTempo + widhTempo, yTempo);
                    SDL_RenderDrawPoint(renderer, xTempo + widhTempo, yTempo + heightTempo);
                    SDL_RenderDrawPoint(renderer, xTempo, yTempo + heightTempo);
                    SDL_RenderDrawPoint(renderer, xTempo + widhTempo, yTempo + heightTempo);

                    SDL_RenderDrawLine(renderer, xTempo, yTempo, xTempo + widhTempo, yTempo);
                    SDL_RenderDrawLine(renderer, xTempo, yTempo, xTempo, yTempo + heightTempo);
                    SDL_RenderDrawLine(renderer, xTempo + widhTempo, yTempo, xTempo + widhTempo, yTempo + heightTempo);
                    SDL_RenderDrawLine(renderer, xTempo + widhTempo, yTempo + heightTempo, xTempo, yTempo + heightTempo);
                    SDL_RenderDrawLine(renderer, xTempo + widhTempo, yTempo + heightTempo, xTempo, yTempo + heightTempo);

                    // Diagonale
                    SDL_RenderDrawLine(renderer, xTempo, yTempo, xTempo + widhTempo, yTempo + heightTempo);
                    SDL_RenderDrawLine(renderer, xTempo + widhTempo, yTempo, xTempo, yTempo + heightTempo);

                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // rouge
                }
            }

        }

         //cout << "Nombre de sprite dans le manager:" << listeSprites.size() <<endl;
       // SDL_RenderPresent(renderer);
    }

    else 
    {
        cout << "Aucun sprite dans le manager de sprite" <<endl;
    }
    
}

void spriteManager::launchModeDebug()
{
    if(listeSprites.size() > 0)
    {
        for(int i = 0; i < listeSprites.size(); i++)
        {
            if(listeSprites[i]->modeDebug==false)
            {
                if(listeSprites[i]->nom =="Background")
                {
                    listeSprites[i]->modeDebug = false;
                }
                else
                {
                    listeSprites[i]->modeDebug = true;
                    //cout << "mode debug activé" << endl;  
                }
                           
            }
            else
            {
                listeSprites[i]->modeDebug = false;
                //cout << "mode debug désactivé" <<endl;
            }
        }
         
    }

    else 
    {
        cout << "Aucun sprite dans le manager de sprite" <<endl;
    }

}