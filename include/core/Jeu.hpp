//
//  Jeu.hpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#ifndef Jeu_hpp
#define Jeu_hpp

#include <stdio.h>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>
#include <unistd.h>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "Partie.hpp"


using namespace std;

class Jeu{
    
    public:
        Jeu();
        ~Jeu();
        void ajoutPartie();
        void supprimerPartie();
        void afficherPartie();
        void chargerPartie();
    
        void purge();
        bool getEtat();
        void Lancement();
        void Stop();
        void afficheMenu();
        void MenuLoop();
        void Save();
        void Load();
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version){
            ar & lesParties;
        }
    private:
        bool etatDuJeu;
        vector <shared_ptr<Partie>> lesParties;
        

};

#endif /* Jeu_hpp */
