//
//  Metier.cpp
//  GestionNew2.0
//
//  Created by Kevin on 11/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#include "Metier.hpp"

using namespace std;

Metier::Metier()
{
    
}

Metier::Metier(int id, string name, string type)
{
    this->id = id;
    this->name = name;
    this->type = type;
}

Metier::~Metier()
{
    
}

int Metier::getId(){
    
    return id;
}

void Metier::setId(int num){
    
    this->id = num;
    
}

string Metier::getName(){
    
    return name;
}

void Metier::setName(string nom){
    this->name = nom;
}

string Metier::getType()
{
    return type;
}

int Metier::getLevelActuel()
{
    return levelActuel;
}

int Metier::getXpTotal()
{
    return xp;
}

void Metier::AffichePaysan()
{
    cout<<"Menu du Metier Paysan" <<endl;
    cout<<"1. Recolte"<<endl;
    cout<<"2. Moudre"<<endl;
    cout<<"Veuillez choisir une action ? " <<endl;
    
    int action = 0;
    cin >> action;
    
}

void Metier::getAction()
{
    string nameMetier = this->getName();
    
    int choixMetier = 0;
    if(nameMetier == "Paysan")
    {
        choixMetier = 1;
    }
    
    if (choixMetier !=0)
    {
        switch (choixMetier)
           {
               case 1:
                   AffichePaysan();
                   break;
                   
               default:
                   cout << "Erreur dans le choix du metier" <<endl;
                   break;
           }
    }
    
    else
    {
        cout << "Erreur dans le choix du metier " << endl;
    }
   
    
}
