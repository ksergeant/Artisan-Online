//
//  Personnage.hpp
//  GestionNew
//
//  Created by Kevin on 22/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#ifndef Personnage_hpp
#define Personnage_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Metier.hpp"
#include <vector>
#include "Objet.hpp"

using namespace std;
class Personnage{
    
public:
    Personnage();
    ~Personnage();
    
    string getName();
    int getLevel();
    void setLevel(int lvl);
    void setName(string nom);
    void getStats();
    void augmenterLevel();
    int getX();
    int getY();
    void afficheObjets();
    void getMetiers();
    void LearnMetier(int idMetier, string nameMetier, string typeMetier);
    void ChoixMetier();
    
    // Fonction sert à la sérialisation
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        // On Rajoute tous les paramétres que l'ont veut sérialiser
        ar & name & level & mesMetiers & x & y & mesObjets;
    }
    
private:
    string name;
    int level;
    vector<shared_ptr<Metier>> mesMetiers;
    vector<shared_ptr<Objet>> mesObjets;
    int x;
    int y;
    
};

#endif /* Personnage_hpp */
