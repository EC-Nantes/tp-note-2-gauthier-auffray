#include <iostream>
#include "joueur.hpp"

//Méthodes
void Joueur_t::addCarte(Carte_t* carte){
    mv_cartes.push_back(carte);
}

void Joueur_t::tirage(Carte_t* carte){
    mv_cartes.push_back(carte);
}