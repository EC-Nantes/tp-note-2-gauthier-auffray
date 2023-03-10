#include "carte.hpp"

Carte_t::Carte_t(CouleurCarte_t couleur, TypeAction_t type, uint8_t nbCase) {
    this->couleur = couleur;
    this->typeAction = type;
    this->nbCase = nbCase;
}

Carte_t::~Carte_t() {
}

std::ostream& operator<<(std::ostream& o, Carte_t& c) {
    o << "Action : " << c.typeAction << " ";
    o << "de " << c.nbCase << " ";
    o << "les tortues de couleur " << c.couleur << " .\n";
    return o;
}