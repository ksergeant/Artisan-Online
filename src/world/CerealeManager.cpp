//
//  CerealeManager.cpp
//  GestionNew2.0
//
//  Created by Kevin on 12/07/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#include "CerealeManager.hpp"

CerealeManager::CerealeManager()
{
   
}

CerealeManager::~CerealeManager()
{
    
}

void CerealeManager::CheckRessources()
{
    cout << "Check des ressources" <<endl;
    for (int i = 0; i < lesCartes.size(); i++)
          {
              cout << lesCartes[i]->getId() << endl;
              cout << lesCartes[i]->getName() << endl;
              lesCartes[i]->afficheCereale();
              cout <<endl;
          }
    
}

void CerealeManager::init(vector <shared_ptr<Carte>> pLesCartes, shared_ptr<Personnage> pLePerso)
{
    this->lesCartes = pLesCartes;
    this->lePerso = pLePerso;
    
    CheckRessources();
    int choix;
    cin >> choix;
}
