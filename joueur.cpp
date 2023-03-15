#include <iostream>
#include "joueur.hpp"

//Méthodes
void Joueur_t::addCarte(Carte_t* carte){
    mv_cartes.push_back(carte);
}

void Joueur_t::choixCarte(){
    std::vector<Carte_t*>::const_iterator it_carte = mv_cartes.begin();
    int choix = 0;
    int i = 1;
    std::cout << "Veuillez choisir une carte en tapant son numero : \n";
    for(it_carte; it_carte != mv_cartes.end(); it_carte++){
        std::cout << "Carte " << i << " - " << **it_carte << "\n";
        i++;
    }
    while ( (choix < 1) || (choix > 5) ){
        std::cout << "Vous devez entrer un numero de 1 a 5 : \n";
        std::cin >> choix;
    }
    m_active_carte = mv_cartes[choix - 1];
    std::cout << "[Selection] Carte " << choix << " - " << *m_active_carte << "\n";
    mv_cartes.erase(mv_cartes.begin() + (choix - 1)); //On supprime la carte de notre jeu
}

void Joueur_t::tirage(){
    //AJouter la dernière carte de la pioche dans mv_cartes
    
}