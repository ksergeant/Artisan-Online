//
//  Batiment.cpp
//  GestionNew2.0
//
//  Created by Kevin on 10/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#include "Batiment.hpp"

using namespace std;

Batiment::Batiment()
{
    
}

Batiment::~Batiment()
{
    
}

int Batiment::getId(){
    
    return id;
}

void Batiment::setId(int num){
    
    this->id = num;
    
}

string Batiment::getName(){
    
    return name;
}

void Batiment::setName(string nom){
    this->name = nom;
}
