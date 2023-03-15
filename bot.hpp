#ifndef BOT_HPP
#define BOT_HPP

#include "carte.hpp"
#include "joueur.hpp"

class Bot_t : public Joueur_t {

    public:
        //Constructeurs
        Bot_t(Couleur_joueur couleur) {}
        Bot_t() {}

        //Méthodes
        void choixCarte();
};
#endif