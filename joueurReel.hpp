#ifndef JOUEUR_REEL_HPP
#define JOUEUR_REEL_HPP

#include "carte.hpp"
#include "joueur.hpp"

class JoueurReel_t : public Joueur_t {

    public:
        //Constructeurs
        JoueurReel_t(Couleur_joueur couleur) : Joueur_t(couleur) {}
        JoueurReel_t() = delete;

        //Méthodes
        void choixCarte();
};
#endif