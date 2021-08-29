//
//  Personnage.cpp
//  GestionNew
//
//  Created by Kevin on 22/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#include "Personnage.hpp"

using namespace std;

Personnage::Personnage()
{
    level = 1;
}

Personnage::~Personnage()
{
    
}

string Personnage::getName()
{
    return name;
}

void Personnage::setName(string nom)
{
    name = nom;
}

void Personnage::augmenterLevel()
{
    level = level +1;
}

void Personnage::getStats()
{
    cout << name << " Lvl " << level << endl;
}

int Personnage::getLevel()
{
    return level;
}

void Personnage::setLevel(int lvl)
{
    level = lvl;
}

int Personnage::getX()
{
    return x;
}

int Personnage::getY(){
    return y;
}

void Personnage::afficheObjets(){
    
    if(mesObjets.size()>0)
    {
        // affichage des objets du Personnage
        for(int i = 0; i < mesObjets.size(); i++)
        {
            cout << "\nAffichage des objets du personnage" <<endl;
            cout << "ID : " << mesObjets[i]->getId() << endl;
            cout << "Nom : " << mesObjets[i]->getName() << endl;
            cout << "Quantite : " << mesObjets[i]->getNombre() << endl << endl;
        }
    
    }else
    {
        cout << "Aucun objets dans le sac" <<endl;
    }
    
}

void Personnage::ChoixMetier()
{
    this->getMetiers();
    int choix = 0;
    cout << "Veuillez choisir le metier pour une action ? id :" << endl;
    cin >> choix;
    
    for (int i = 0; i<mesMetiers.size();i++)
    {
        if(choix == mesMetiers[i]->getId())
        {
            mesMetiers[i]->getAction();
        }
    }
    
}

void Personnage::getMetiers(){
    
    if(mesMetiers.size()>0)
    {
        // affichage des objets du Personnage
        for(int i = 0; i < mesMetiers.size(); i++)
        {
            cout << "\nAffichage des metiers du personnage" <<endl;
            cout << "ID : " << mesMetiers[i]->getId() << endl;
            cout << "Nom : " << mesMetiers[i]->getName() << endl;
            cout << "Level actuel : " << mesMetiers[i]->getLevelActuel() << endl;
            cout << "XP Total : " << mesMetiers[i]->getXpTotal() << endl << endl;
        }
    
    }else
    {
        cout << "Aucun metiers" <<endl;
    }
    
}

void Personnage::LearnMetier(int idMetier, string nameMetier, string typeMetier)
{
    // shared_ptr pointeur intelligent et make_shared remplace le new
    
    shared_ptr<Metier> ptr(make_shared<Metier>(idMetier, nameMetier, typeMetier));
    mesMetiers.push_back(ptr);
    cout << "Un nouveau metier a ete appris " << nameMetier << endl;
           
}
