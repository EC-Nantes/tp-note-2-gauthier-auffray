#include <iostream>
#include "joueur.hpp"

//Méthodes
void Joueur_t::addCarte(Carte_t* carte){
    mv_cartes.push_back(carte);
}

void Joueur_t::tirage(Carte_t* carte){
    mv_cartes.push_back(carte);
}

Couleur_joueur Joueur_t::getCouleur() {
    return m_couleur;
}

std::ostream& operator<<(std::ostream& o, Joueur_t& c) {
    std::string couleur;
    switch(c.getCouleur()) {
    case Couleur_joueur::BLEU_J:
        couleur = "bleu";
        break;
    case Couleur_joueur::JAUNE_J:
        couleur = "jaune";
        break;
    case Couleur_joueur::ROUGE_J:
        couleur = "rouge";
        break;
    case Couleur_joueur::VERT_J:
        couleur = "vert";
        break;
    case Couleur_joueur::VIOLET_J:
        couleur = "violet";
        break;
    default:
        couleur = "error";
        break;
    }
    o << "Joueur : couleur = " << couleur << "\n"; //<< "Cartes :\n";
    // std::vector<Carte_t*>::iterator it;
    // for(it = c.mv_cartes.begin(); it != c.mv_cartes.end(); it++) {
    //     o << *(*it);
    // }
    return o;
}