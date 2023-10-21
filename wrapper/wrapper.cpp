//
//  wrapper.cpp
//  
//  Created by Moks on 10/10/2023.
//  Copyright © 2023 Moks. All rights reserved.
//

#include "wrapper.hpp"

wrapper::wrapper()
{

}

wrapper::~wrapper()
{
    
}

int wrapper::wrapper_init()
{
    // Initialisation de la SDL2
    cout << "Start\n";
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Failed to initialise SDL\n";
        return -1;
    }
    return 0;
}