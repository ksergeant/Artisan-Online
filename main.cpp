#include <iostream> // cout
#include <memory> // Smart Pointers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.hpp"
#include "spriteManager.hpp"
#include "header/fonction.hpp"
#include "header/class.hpp"
#include "Moks/header/Moks.hpp"
#include "Jeu.hpp"
#include "player.hpp"
#include <array>

using namespace std;

int main(int argc, char *argv[])
{
    // Chargement du fichier de sauvegarde du jeu
    boost::shared_ptr<Jeu> myGame (boost::make_shared<Jeu>());
    
    /* 
    cout << "Chargement des données \n";
    // Chargement des données
    std::ifstream ifile("Save");
    boost::archive::text_iarchive iTextArchive(ifile);
    iTextArchive >> myGame;     // désérialisation dans d
        
    // Sauvegarde du l'objet jeu dans un fichier
    cout << "\n Sauvegarde des données \n";
    std::ofstream ofile("Save");
    boost::archive::text_oarchive oTextArchive(ofile);
    oTextArchive << myGame;    // sérialisation de d
*/
    cout <<endl;
    // Initialisation de la SDL2
    cout << "Start\n";
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Failed to initialise SDL\n";
        return -1;
    }

    // Creation de la fenêtre principale
    SDL_Window *window = SDL_CreateWindow("Artisan Online", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    1440, 800, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        SDL_Log("Could not create a window: %s", SDL_GetError());
        return -1;
    }

    // Creation du renderer correspondant à la fenêtre principale (1 renderer par fenêtre)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        SDL_Log("Could not create a renderer: %s", SDL_GetError());
        return -1;
    }

    // Creation du manager de sprite
    spriteManager mySpriteManager;

    // Chemin des images
    string path1 = "Map1.png";
    string path2 = "perso_tilesheet.png";

    // Creation et ajout des sprites dans le Manager
    mySpriteManager.addSprite("Background", -150, -150, 3, 3, path1);
   // mySpriteManager.addSprite("TileSheetPerso", 0, 0, 1, 1, path2);
     
    // Création de la tilesheet 32x32
    int tileWidth = 32;
    int tileHeight = 32;
    player player1("Kirito", 40, 40);
    player1.setSpriteSheet(renderer, path2, tileWidth, tileHeight, 32, 32, 0, 0);
    cout << "Liste de rectangle du player 1 : " << player1.listeRect.size() << endl;
    vector<int> arrTest1;
    arrTest1.push_back(0);
    arrTest1.push_back(1);
    arrTest1.push_back(2);
    player1.recToAnimation(arrTest1,"Animation1");
    cout << "Liste de rectangle de la premiere animation : "<<player1.listeAnimation[0]->listeRectAni.size() << endl;

/* 
int posY=0;
    for (int i2=0; i2 < 5; i2++)
    {
        int posX=0;
        for (int i=0; i < 19; i++)
        {
            mySpriteManager.addSprite("Brique", posX, posY, 0.2, 0.2, path2);

            posX = posX + 76;
        }

        posY = posY + 25;
    }

*/
    // Chargement des textures de tous les sprites
    mySpriteManager.loadAllTexture(renderer);
   
    // Boucle globale tant que la fenetre est ouverte
    int posY =0;
    while (true)
    {
        SDL_Event event;
        
        if (SDL_PollEvent(&event))
        {
           int Deplacement = 20;
            switch(event.key.keysym.sym)
            {
                case SDLK_LEFT:
                    player1.move(0,Deplacement);
                    cout << "move LEFT" << endl;
                    break;
                case SDLK_RIGHT:
                    player1.move(1,Deplacement);
                    cout << "move RIGHT" << endl;
                    break;
                case SDLK_UP:
                    player1.move(2,Deplacement);
                    cout << "move UP" << endl;
                    break;
                case SDLK_DOWN:
                    player1.move(3,Deplacement);
                    cout << "move DOWN" << endl;
                    break;

                default:
                    break;

            }


            if (event.type == SDL_QUIT)
            {
                break;
            }
        }


/* 
Uint32 ticks = SDL_GetTicks();
Uint32 delai = (ticks / 90) % 4;
if (delai == 0) 
{
    posY = 5;
}
if (delai ==1) 
{
    posY = 10;
}
if (delai >=3) 
{
    delai =2;
    posY = 15;
}

*/
SDL_Rect test ={player1.x, player1.y, 64, 64};
//cout << delai <<endl;

        SDL_RenderClear(renderer);
         // Affichage de tous les sprites par ordre d'ajout dans le vecteur des sprites
        mySpriteManager.update(renderer);
        SDL_RenderCopy(renderer, player1.texture, &player1.listeAnimation[0]->listeRectAni[0], &test);

        SDL_RenderPresent(renderer);
       

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
