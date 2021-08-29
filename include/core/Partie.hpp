//  Partie.hpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#ifndef Partie_hpp
#define Partie_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Personnage.hpp"
#include "Carte.hpp"
#include "Metier.hpp"
#include <unistd.h>
#include "CerealeManager.hpp"

using namespace std;

class Partie{
    
public:
    Partie();
    ~Partie();
    Partie(string name,int num);
    
    int getNum();
    void setNum(int num);
    string getName();
    void setName(string nom);
    void getPerso();
    void up();
    void PartieLoop();
    void initMetiers();
    void initCartes();
    void initCerealeManager();
    void afficheMenuPartie();
    void afficheInfosPartie();
    void afficheInfosPerso();
    void afficheInfosCarte();
    void afficheSac();
    void ApprendreMetiers();
    void ActionMetier();
    void QuittePartie();
    void Clean();

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
         ar & num & name & monPerso & lesCartes & lesMetiers
        & carteActuelle & myCerealeManager;
    }
    
private:
    int num;
    string name;
    Personnage monPerso;
    Carte carteActuelle;
    CerealeManager myCerealeManager;
    vector <shared_ptr<Carte>> lesCartes;
    vector <shared_ptr<Metier>> lesMetiers;
    bool PartieEnCours = false;
    
};


#endif /* Partie_hpp */
