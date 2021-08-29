//
//  Map.hpp
//  GestionNew2.0
//
//  Created by Kevin on 08/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#ifndef Carte_hpp
#define Carte_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Cereale.hpp"
#include "Batiment.hpp"
//#include <boost/serialization/shared_ptr.hpp>
//#include <boost/serialization/vector.hpp>

using namespace std;

class Carte{
    
public:
    Carte();
    Carte(int id, string name);
    ~Carte();
    
    int getId();
    void setId(int num);
    string getName();
    void setName(string nom);
    void afficheCereale();
    void CreationCereale(int nombre, string nameCereale);

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
         ar & id & name & lesCereales & lesBatiments;
    }
    
private:
    int id = 0;
    string name;
    vector <shared_ptr<Cereale>> lesCereales;
    vector <shared_ptr<Batiment>> lesBatiments;

};

#endif /* Carte_hpp */
