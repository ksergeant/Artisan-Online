//
//  Partie.cpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#include "Partie.hpp"

using namespace std;

Partie::Partie()
{
    
}

Partie::~Partie()
{
    
}

Partie::Partie(string name, int num)
{
    this->name = name;
    this->num = num;
    string nom;
    
    cout << "Création du personnage veuillez choisir un nom -> " ;
    cin >> nom ;
    this->monPerso.setName(nom);
}


int Partie::getNum()
{
    return num;
}

string Partie::getName()
{
    return name;
}

void Partie::setName(string nom)
{
    name = nom;
}

void Partie::setNum(int num)
{
    this->num = num;
}

void Partie::getPerso()
{
    monPerso.getStats();
}

void Partie::initCartes()
{
    // shared_ptr pointeur intelligent et make_shared remplace le new
    int id = 1;
    string name = "Carte 1";
    
    shared_ptr<Carte> ptr(make_shared<Carte>(id, name));
    lesCartes.push_back(ptr);
        
    for (int i = 0; i < lesCartes.size(); i++)
    {
        if (lesCartes[i]->getId()==1)
        {
            lesCartes[i]->CreationCereale(4, "Ble");
        }
        
    }
    
}

void Partie::initCerealeManager()
{
    shared_ptr<Personnage> ptrPerso(make_shared<Personnage>(monPerso));
    cout <<"Creation du Cereale Manager"<<endl;
    this->myCerealeManager.init(lesCartes, ptrPerso);
    
}
void Partie::initMetiers()
{
    // shared_ptr pointeur intelligent et make_shared remplace le new
    int id = 1;
    string name = "Paysan";
    string type = "Recolte";
    shared_ptr<Metier> ptr(make_shared<Metier>(id, name, type));
     
     lesMetiers.push_back(ptr);
    
    for (int i = 0; i < lesMetiers.size(); i++)
    {
        cout << lesMetiers[i]->getId() << endl;
        cout << lesMetiers[i]->getName() << endl;
        cout << lesMetiers[i]->getType() << endl;
    }
    
}

void Partie::ApprendreMetiers()
{
    cout <<"Bienvenue à l'hotel des artisans"<<endl;
    
    if (lesMetiers.size() == 0)
    {
        cout << "-> Aucun Metier est disponible" <<endl;
    }
    
    else
    {
        cout <<"Voici les metiers disponibles" <<endl;
        for (int i = 0; i < lesMetiers.size(); i++)
        {
            cout << "ID: " << lesMetiers[i]->getId() <<
            " Nom: "<< lesMetiers[i]->getName() <<
            " Type: " << lesMetiers[i]->getType() << endl;

        }
        int choix = 0;
        cout << "\n###Veuillez choisir un metier ? id : ";
        cin >> choix;
        
        for (int i = 0; i<lesMetiers.size();i++)
        {
            if(choix == lesMetiers[i]->getId())
            {
                int idMetierTempo = lesMetiers[i]->getId();
                string nameMetierTempo = lesMetiers[i]->getName();
                string typeMetierTempo = lesMetiers[i]->getType();
                monPerso.LearnMetier(idMetierTempo, nameMetierTempo, typeMetierTempo);
            }
        }
    }
}


void Partie::ActionMetier()
{
    monPerso.ChoixMetier();
}

void Partie::up()
{
    monPerso.augmenterLevel();
}

void Partie::PartieLoop()
{
    this->PartieEnCours = true;
    
    if (lesMetiers.size()==0)
    {
        initMetiers();
    }
    
    if (lesCartes.size()==0)
    {
        initCartes();
    }
    
    initCerealeManager();
    
    int choix = 0;
    while(this->PartieEnCours == true)
    {
        this->Clean();
        this->afficheMenuPartie();
        cin >> choix;
        
        switch (choix)
        {
            // Affiche les infos de la partie
            case 1: afficheInfosPartie();break;
                
            // Affiche les infos du personnage
            case 2: afficheInfosPerso();break;
                
            // Affiche les infos de la carte
            case 3: afficheInfosCarte();break;
                
            // Affiche le sac
            case 4: afficheSac();break;
                
            // Apprendre un metier
            case 5: ApprendreMetiers();break;
            
            // Action Métiers
            case 6: ActionMetier();break;
                
            // Quitte de la partie
            case 7: QuittePartie();break;
                
            default: cout <<"Erreur"<<endl; break;
        }
    }
}

void Partie::Clean()
{
    usleep(2000000);
    system("clear");
}


void Partie::afficheMenuPartie()
{
    cout << "1. Affiche les informations de la partie " <<endl;
    cout << "2. Affiche les informations du personnage " <<endl;
    cout << "3. Affiche les informations de la Carte" <<endl;
    cout << "4. Affiche le sac" <<endl;
    cout << "5. Apprendre un metier" <<endl;
    cout << "6. Action Metier" << endl;
    cout << "7. quitter la partie" <<endl;
    
}

void Partie::afficheInfosPartie()
{
    cout << "ID de la partie : " << this->num <<endl;
    cout << "Nom de la partie : " << this->name <<endl;
    cout << "Nom du personnage : "<< this->monPerso.getName()<<endl;
}

void Partie::afficheInfosPerso()
{
    cout << "Nom du personnage : "<< this->monPerso.getName()<<endl;
    this->monPerso.getStats();
    cout << endl;
    cout << "Position X : "<< this->monPerso.getX()<<endl;
    cout << "Position X : "<< this->monPerso.getY()<<endl;
    
}

void Partie::afficheInfosCarte()
{
    for (int i = 0; i < lesCartes.size(); i++)
       {
           cout << lesCartes[i]->getId() << endl;
           cout << lesCartes[i]->getName() << endl;
           lesCartes[i]->afficheCereale();
           cout <<endl;
       }
}

void Partie::afficheSac()
{
    this->monPerso.afficheObjets();
}


void Partie::QuittePartie()
{
    this->PartieEnCours =false;
}
