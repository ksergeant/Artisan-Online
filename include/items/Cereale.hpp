//
//  Cereale.hpp
//  GestionNew2.0
//
//  Created by Kevin on 11/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#ifndef Cereale_hpp
#define Cereale_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Objet.hpp"

using namespace std;

class Cereale : public Objet {
    
public:
    Cereale();
    Cereale(int id, string nameCereale, int posX, int posY);
    ~Cereale();
    
    string getEtat();
    int getPosX();
    int getPosY();
    
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
         ar & id & name & etat & posX & posY;
    }
    
    
private:
    string etat;
    int posX;
    int posY;
    

};
#endif /* Cereale_hpp */
