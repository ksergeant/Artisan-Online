//
//  Cereale.cpp
//  GestionNew2.0
//
//  Created by Kevin on 11/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#include "Cereale.hpp"

using namespace std;

Cereale::Cereale()
{
    
}

Cereale::Cereale(int id, string nameCereale, int posX, int posY)
{
    this->id = id;
    this->name = nameCereale;
    this->posX = posX;
    this->posY = posY;
}

Cereale::~Cereale()
{
    
}

string Cereale::getEtat(){
  
    return etat;
}

int Cereale::getPosX(){
    
    return posX;
}

int Cereale::getPosY(){
    
    return posY;
}
