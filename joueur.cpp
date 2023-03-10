#include <iostream>
#include "joueur.hpp"

void Joueur_t::choixCarte(){

    std::cout << "Veuillez choisir une carte : \n";
    for(it_carte; it_carte != mv_cartes.end(); it_carte++){
        std::cout << "1" << **it_carte;
    }

}

void Joueur_t::tirage(){
    
}