#include "plateau.hpp"

void Plateau_t::initPioche() {
    CouleurCarte_t couleur = CouleurCarte_t::ROUGE;
    TypeAction_t typeAction;
    for(int i = 0; i < 5; i++) {
        typeAction = TypeAction_t::AVANCER;
        Carte_t carte(couleur, typeAction, 2);
        mv_pioche.push_back(&carte);
        for(int j = 0; j < 5; j++) {
            Carte_t carte(couleur, typeAction, 1);
            mv_pioche.push_back(&carte);
        }
        typeAction = TypeAction_t::RECULER;
        for(int j = 0; j < 2; j++) {
            Carte_t carte(couleur, typeAction, 1);
            mv_pioche.push_back(&carte);
        }
        couleur = static_cast<CouleurCarte_t>(i);
    }
    couleur = CouleurCarte_t::NEUTRE;
    typeAction = TypeAction_t::DERNIER;
    for(int i = 0; i < 2; i++) {
        Carte_t carte(couleur, typeAction, 2);
        mv_pioche.push_back(&carte);
    }
    for(int i = 0; i < 3; i++) {
        Carte_t carte(couleur, typeAction, 1);
        mv_pioche.push_back(&carte);
    }
    typeAction = TypeAction_t::AVANCER;
    for(int i = 0; i < 5; i++) {
        Carte_t carte(couleur, typeAction, 1);
        mv_pioche.push_back(&carte);
    }
    typeAction = TypeAction_t::RECULER;
    for(int i = 0; i < 2; i++) {
        Carte_t carte(couleur, typeAction, 1);
        mv_pioche.push_back(&carte);
    }

    // To do : mélanger le paquet.
}