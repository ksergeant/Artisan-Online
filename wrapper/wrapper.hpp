//
//  wrapper.hpp
//  
//
//  Created by Moks on 10/10/2023.
//  Copyright © 2023 Moks. All rights reserved.
//

#ifndef wrapper_hpp
#define wrapper_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>
#include <unistd.h>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class wrapper{
    
    public:
        wrapper();
        ~wrapper();
        int wrapper_init();

    private:
       
};

#endif /* wrapper_hpp */
