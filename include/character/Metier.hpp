//
//  Metier.hpp
//  GestionNew2.0
//
//  Created by Kevin on 11/02/2021.
//  Copyright © 2021 Moks. All rights reserved.
//

#ifndef Metier_hpp
#define Metier_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Metier{
    
public:
    Metier();
    Metier(int id, string name, string type);
    ~Metier();
    
    int getId();
    void setId(int num);
    string getName();
    void setName(string nom);
    string getType();
    int getLevelActuel();
    int getXpTotal();
    void AffichePaysan();
    void getAction();
 
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version){
         ar & id & name & type & levelMax & levelActuel & vitesseExecution & xp;
    }
    
private:
    int id = 0;
    string name;
    string type;
    int levelMax = 100;
    int levelActuel = 1;
    int vitesseExecution = 12;
    int xp = 0;
    
};

#endif /* Metier_hpp */
