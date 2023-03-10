#include "carte.hpp"

Carte_t::Carte_t(CouleurCarte_t couleur, TypeAction_t type, uint8_t nbCase) {
    this->couleur = couleur;
    this->typeAction = type;
    this->nbCase = nbCase;
}

Carte_t::~Carte_t() {
}