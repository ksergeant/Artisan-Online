//
//  Jeu.cpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#include "Jeu.hpp"

Jeu::Jeu(){
    
    this->etatDuJeu = false;
}

Jeu::~Jeu(){
    
}

void Jeu::purge(){
    usleep(2000000);
    system("clear");
}

void Jeu::Lancement(){
    etatDuJeu = true;
}

void Jeu::Stop(){
    etatDuJeu = false;
}

void Jeu::ajoutPartie(){
    cout << "\n->Ajout de partie ";
    string name;
    cout << "Nom de la partie ? ";
    cin >> name;
    
    // shared_ptr pointeur intelligent et make_shared remplace le new
    shared_ptr<Partie> ptr(make_shared<Partie>(name,lesParties.size()+1));
    
    lesParties.push_back(ptr);
    
}

void Jeu::afficherPartie(){
    cout << "\n### Affichage des parties ###"<<endl;
    if(lesParties.size()==0){
        cout << "->Aucune Partie";
    }
    else{
        for(int i = 0; i<lesParties.size();i++){
            cout << "Partie nom : " << lesParties[i]->getName()<<" id : " << lesParties[i]->getNum()<<endl;
            cout << "Héros " ;
            lesParties[i]->getPerso() ;
        }
    }
}

void Jeu::supprimerPartie(){
    afficherPartie();
    int num,num2 = 0;
    bool find = false;
    cout << "\nSuppression de la partie ? id : ";
    cin >> num;
    for (int i = 0; i<lesParties.size();i++){
        
        if(num == lesParties[i]->getNum()){
            lesParties.erase(lesParties.begin()+i);
            num2 = i; //position dans le vector donc num -1
            find = true;
        }
    }
    
    // si la suppression fonctionne on met à jour les id dans le vector
    if (find==true && lesParties.size()>0){
        for(int k = num2; k<lesParties.size();k++){
            
            lesParties[k]->setNum(k+1);
        }
    }
}

void Jeu::chargerPartie()
{
    int choix = 0;
    cout << "\n### Affichage des parties ###"<<endl;
       if(lesParties.size()==0)
       {
           cout << "->Aucune Partie";
       }
       else{
            for(int i = 0; i<lesParties.size();i++)
            {
               cout << "Partie nom : " << lesParties[i]->getName()<<" id : " << lesParties[i]->getNum()<<endl;
               cout << "Héros " ;
               lesParties[i]->getPerso() ;
            }
            cout << "\n###Veuillez choisir une partie ? id : ";
            cin >> choix;
          
           for (int i = 0; i<lesParties.size();i++)
           {
           
               if(choix == lesParties[i]->getNum())
               {
                   lesParties[i]->PartieLoop();
               }
           
           }
        }
}
bool Jeu::getEtat(){
    
    return etatDuJeu;
}

void Jeu::afficheMenu(){
    cout << "\n#### Menu Principal du Jeu ####" <<endl <<endl;
    cout << "1: Afficher les parties " <<endl;
    cout << "2: Nouvelle partie " <<endl;
    cout << "3: Charger une partie"<<endl;
    cout << "4: Supprimer une partie" <<endl;
    cout << "5: Quitter le jeu" <<endl<<endl;
    
    cout << "Votre choix -> ";

}

void Jeu::MenuLoop(){
    
    Lancement();
    int choix;
    
    while(etatDuJeu == true){
        purge();
        afficheMenu();
        
        cin >> choix;
        
        switch (choix) {
            case 1:
                afficherPartie();
                break;
            case 2:
                ajoutPartie();
                break;
            case 3:
                chargerPartie();
                break;
            case 4:
                supprimerPartie();
                break;
            case 5:
                 Stop();
                break;
            default:
                cout << "Erreur de Choix "<<endl;
                break;
        }
        
        
    }
    
}


