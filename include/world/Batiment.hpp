//
//  Batiment.hpp
//  GestionNew2.0
//
//  Created by Kevin on 10/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#ifndef Batiment_hpp
#define Batiment_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Batiment{
    
public:
    Batiment();
    ~Batiment();
    
    int getId();
    void setId(int num);
    string getName();
    void setName(string nom);
 

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
         ar & id & name;
    }
    
private:
    int id = 0;
    string name;
    

};

#endif /* Batiment_hpp */
