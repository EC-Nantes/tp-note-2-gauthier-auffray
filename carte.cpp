#include "carte.hpp"

Carte_t::Carte_t(CouleurCarte_t couleur, TypeAction_t type, uint8_t nbCase) {
    m_couleur = couleur;
    m_typeAction = type;
    m_nbCase = nbCase;
}

Carte_t::~Carte_t() {
}

std::ostream& operator<<(std::ostream& o, Carte_t& c) {
    std::string action = "";
    std::string couleur = "";

    switch (c.m_typeAction){
        case 0:
            action = "Avancer";
            break;
        case 1:
            action = "Reculer";
            break;
        case 2:
            action = "Avancer";
            break;
        default:
            action = "error";
    }

    switch (c.m_couleur){
        case 0:
            couleur = "rouge";
            break;
        case 1:
            couleur = "bleu";
            break;
        case 2:
            couleur = "vert";
            break;
        case 3:
            couleur = "jaune";
            break;
        case 4:
            couleur = "violet";
            break;
        case 5:
            couleur = "neutre";
            break;
        default:
            couleur = "error";
    }

    if (c.m_couleur == 5) {
        if (c.m_typeAction != 2) {
            o << "Action : " << action << " ";
            o << "de " << unsigned(c.m_nbCase) << " case(s) ";
            o << "une tortue de la couleur de votre choix.\n";
        }
        else { //DERNIERES
            o << "Action : " << action << " ";
            o << "de " << unsigned(c.m_nbCase) << " cases ";
            o << "une ou les tortues presentes sur la derniere case.\n";
        }
    }
    else {
        o << "Action : " << action << " ";
        o << "de " << unsigned(c.m_nbCase) << " cases ";
        o << "les tortues de couleur " << couleur << ".\n";  
    }
    return o;
}