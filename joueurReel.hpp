#ifndef JOUEUR_REEL_HPP
#define JOUEUR_REEL_HPP

#include "carte.hpp"
#include "joueur.hpp"

class JoueurReel_t : public Joueur_t {

    public:
        //Constructeurs
        JoueurReel_t(Couleur_joueur couleur) {}
        JoueurReel_t() {}

        //Méthodes
        void choixCarte();
};
#endif