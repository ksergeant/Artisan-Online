#include "spriteManager.hpp"

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

void spriteManager::cutTileSheet(string nom, int x, int y, double scaleX, double scaleY, string path_image, int tileWidth, int tileHeight, SDL_Renderer *renderer)
{
    sprite spriteTempo(nom, x, y, scaleX, scaleY, path_image);
    shared_ptr<sprite> ptr(make_shared<sprite>(spriteTempo));
    spriteTempo.LoadTexture(renderer);
}

 void spriteManager::loadAllTexture(SDL_Renderer *renderer)
{
    if (listeSprites.size() > 0)
    {
        for (int i = 0; i < listeSprites.size(); i++)
        {
            listeSprites[i]->LoadTexture(renderer);
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
            SDL_RenderCopy(renderer, listeSprites[i]->texture, NULL, &listeSprites[i]->rectangle);

            if(listeSprites[i]->modeDebug==true)
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