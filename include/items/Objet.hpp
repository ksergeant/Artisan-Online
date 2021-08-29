//
//  Objet.hpp
//  GestionNew2.0
//
//  Created by Kevin on 13/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#ifndef Objet_hpp
#define Objet_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Classe Abstraite

class Objet{
    
public:
    Objet();
    ~Objet();
    
    virtual int getId();
    virtual void setId(int num);
    virtual string getName();
    virtual void setName(string nom);
    virtual int getNombre();
    
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
        ar & id & name & nombre;
    }
    
protected:
    int id = 0;
    string name;
    int nombre;
    
};

#endif /* Objet_hpp */
