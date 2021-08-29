//
//  Objet.cpp
//  GestionNew2.0
//
//  Created by Kevin on 13/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#include "Objet.hpp"

Objet::Objet()
{
    
}

Objet::~Objet()
{
    
}

int Objet::getId(){
    
    return id;
}

void Objet::setId(int num){
    
    this->id = num;
    
}

string Objet::getName(){
    
    return name;
}

void Objet::setName(string nom){
    this->name = nom;
}

int Objet::getNombre(){
    
    return nombre;
}
