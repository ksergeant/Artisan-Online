#include "../header/Moks.hpp" 

using std::cout;

/* 
int initial(){
  cout << "Start\n";
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Failed to initialise SDL\n";
        return -1;
    }
}

SDL_Window *window = SDL_CreateWindow("Editeur 0.1",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          1440,
                                          800,
                                          SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        SDL_Log("Could not create a window: %s", SDL_GetError());
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        SDL_Log("Could not create a renderer: %s", SDL_GetError());
        return -1;
    }
   
   SDL_Surface *sapin = NULL;

    sapin = IMG_Load("background.png");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, sapin);
    
    while (true)
    {
        SDL_Event event;
        
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }


        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(sapin);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    */