//
//  Carte.cpp
//  GestionNew2.0
//
//  Created by Kevin on 08/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#include "Carte.hpp"

using namespace std;

Carte::Carte()
{
    
}

Carte::Carte(int id, string name)
{
    this->id = id;
    this->name = name;
}


Carte::~Carte()
{
    
}

int Carte::getId(){
    
    return id;
}

void Carte::setId(int num){
    
    this->id = num;
    
}

string Carte::getName(){
    
    return name;
}

void Carte::setName(string nom){
    this->name = nom;
}

void Carte::CreationCereale(int nombre, string nameCereale)
{
    cout << "Creation de cereale de type : " << nameCereale <<endl;
    
    int posX = 10;
    int posY = 10;
    for (int i = 0; i < nombre ; i++)
    {
        id = int(lesCereales.size())+1;
        
        
        shared_ptr<Cereale> ptr(make_shared<Cereale>(id, nameCereale, posX, posY));
        
        lesCereales.push_back(ptr);
        
        posX = posX +10;
        posY = posY +10;
    }
    
}

void Carte::afficheCereale(){
    
    cout << "Nombre de cereales sur la carte : " << lesCereales.size() <<endl;
    
    for (int i = 0; i < lesCereales.size(); i++)
    {
        cout << "ID : " << lesCereales[i]->getId() << endl;
        cout << "Nom: "<< lesCereales[i]->getName() << endl;
        cout << "Etat :"<< lesCereales[i]->getEtat() << endl;
        cout << "Position : " << lesCereales[i]->getPosX() << " " << lesCereales[i]->getPosY() <<endl;
    }
    
}
