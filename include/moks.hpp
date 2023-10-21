//
//  moks.hpp
//
//  Created by Moks on 21/10/2023.
//  Copyright © 2023 Moks. All rights reserved.
//

#ifndef moks_hpp
#define moks_hpp

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
#include <iostream>

using namespace std;

class Moks{
    
    public:
        Moks();
        ~Moks();
        
    private:
    
};

#endif /* Moks_hpp */
