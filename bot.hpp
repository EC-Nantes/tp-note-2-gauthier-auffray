#ifndef BOT_HPP
#define BOT_HPP

#include "carte.hpp"
#include "joueur.hpp"

class Bot_t : public Joueur_t {

    public:
        //Constructeurs
        Bot_t(Couleur_joueur couleur) : Joueur_t(couleur) {}
        Bot_t() = delete;

        //Méthodes
        void choixCarte();
};
#endif