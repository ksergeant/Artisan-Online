//
//  CerealeManager.hpp
//  GestionNew2.0
//
//  Created by Kevin on 12/07/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#ifndef CerealeManager_hpp
#define CerealeManager_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Carte.hpp"
#include "Personnage.hpp"

using namespace std;

class CerealeManager{
    
public:
    CerealeManager();
    ~CerealeManager();
    
    int getId();
    void CheckRessources();
    void init(vector <shared_ptr<Carte>> pLesCartes, shared_ptr<Personnage> pLePerso);
 
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
         ar & lesCartes & lePerso;
    }
    
private:
    vector <shared_ptr<Carte>> lesCartes;
    shared_ptr<Personnage> lePerso;
};


#endif /* CerealeManager_hpp */


