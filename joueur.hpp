#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include "carte.hpp"

enum Couleur_joueur {
        ROUGE,
        BLEU,
        VERT,
        JAUNE,
        VIOLET
    };

class Joueur_t{

    private:
        std::vector<Carte_t*> mv_cartes;
        Carte_t* m_active_carte;
        std::vector<Carte_t*>::const_iterator it_carte = mv_cartes.begin();

    public:
        Joueur_t(Couleur_joueur couleur);
        Joueur_t(/* args */);
        ~Joueur_t();

        //Méthodes
        void choixCarte();
        void tirage();
};

Joueur_t::Joueur_t(Couleur_joueur couleur){
}

Joueur_t::~Joueur_t(){
}

#endif