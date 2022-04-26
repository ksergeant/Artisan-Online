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
#include <sstream>
#include <array>

using namespace std;

int main(int argc, char *argv[])
{

    bool quit = false;
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
    bool modeDebug=false;

    // Chemin des images
    string path1 = "Map1.png";
    string path2 = "perso_tilesheet.png";
    string path3 = "buttonSquare_blue.png";
    string path4 = "buttonSquare_blue_pressed.png";
    string path5 = "Transperent/Icon1.png";

    // Creation et ajout des sprites dans le Manager
    mySpriteManager.addSprite("Background", 0, 0, 2, 2, path1);
    mySpriteManager.addSprite("Bouton1", 300, 300, 1, 1, path3);
    mySpriteManager.addSprite("Fish1", 860, 400, 1, 1, path5);
    //mySpriteManager.addSprite("Bouton1Pressed", 300, 300, 1,1, path4);
    //mySpriteManager.addSprite("TileSheetPerso", 0, 0, 1, 1, path2);
     
    // Création de la tilesheet 32x32
    int tileWidth = 32;
    int tileHeight = 32;
    player player1("Kirito", 40, 40);

    //SDL_Renderer *renderer, string path_image, int tileWidth, int tileHeight, int decalX, int decalY, int debutX, int debutY)

    player1.setSpriteSheet(renderer, path2, tileWidth, tileHeight, 32, 32, 0, 0);
    cout << "Liste de rectangle du player 1 : " << player1.listeRect.size() << endl;
    vector<int> arrTest1;
    arrTest1.push_back(0);
    arrTest1.push_back(1);
    arrTest1.push_back(2);
    player1.recToAnimation(arrTest1,"Animation1");
    cout << "Liste de rectangle de la premiere animation : "<< player1.listeAnimation[0]->listeRectAni.size() << endl;

    // Chargement des textures de tous les sprites
    mySpriteManager.loadAllTexture(renderer);
    
    // Boucle globale tant que la fenetre est ouverte
    int posY =0;
    while (!quit)
    {
        SDL_Event event;
        
        if (SDL_PollEvent(&event))
        {
           int Deplacement = 20;
          // cout << player1.x << " - " << player1.y <<endl;
            if (player1.x >=440 && player1.x<=500 && player1.y>=260 && player1.y<=280)
            {
                cout << "Un Poisson est à portée" << endl;
            }
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;

                // si une touche est pressée on rentre dans ce switch
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_LEFT: player1.move(0,Deplacement);cout << "move LEFT" << endl;break;
                        case SDLK_RIGHT: player1.move(1,Deplacement);cout << "move RIGHT" << endl;break;
                        case SDLK_UP: player1.move(2,Deplacement);cout << "move UP" << endl;break;
                        case SDLK_DOWN: player1.move(3,Deplacement);cout << "move DOWN" << endl;break;
                        case SDLK_d: mySpriteManager.launchModeDebug();break;
                        default:break;
                    }
                break;

                // si la souris est utilisée on rentre dans ce switch
                case SDL_MOUSEBUTTONDOWN:
                    switch (event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            //SDL_ShowSimpleMessageBox(0, "Mouse", "pLeft button was pressed!", window);
                            cout << "Mouse Left button was pressed!" << endl;
                            break;
                        case SDL_BUTTON_RIGHT:
                            //SDL_ShowSimpleMessageBox(0, "Mouse", "Right button was pressed!", window);
                            cout << "Mouse Right button was pressed!" << endl;

                            break;
                        default:
                           // SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", window);
                            cout << "Mouse Some other button was pressed!" << endl;

                            break;
                    }
                    break;

                case SDL_MOUSEMOTION:
                    int mouseX = event.motion.x;
                    int mouseY = event.motion.y;
 
                    std::stringstream ss;
                    ss << "X: " << mouseX << " Y: " << mouseY;
 
                    SDL_SetWindowTitle(window, ss.str().c_str());
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

       
        int tailleW = 64;
        int tailleH = 64;
        SDL_Rect test ={player1.x, player1.y, tailleW, tailleH};
        //cout << delai <<endl;

        SDL_RenderClear(renderer);

         // Affichage de tous les sprites par ordre d'ajout dans le vecteur des sprites
        mySpriteManager.update(renderer);
        SDL_RenderCopy(renderer, player1.texture, &player1.listeAnimation[0]->listeRectAni[0], &test);
        //SDL_RenderSetScale(renderer, 1, 1);

        SDL_RenderPresent(renderer);
    
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
