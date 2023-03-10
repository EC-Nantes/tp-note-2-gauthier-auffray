#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include "carte.hpp"

class Joueur_t{
    enum Couleur_carte {
        ROUGE,
        BLEU,
        VERT,
        JAUNE,
        Violet
    };

    private:
        std::vector<Carte_t*> mv_cartes;
        Carte_t* m_active_carte;
        /* data */
    public:
        Joueur_t(Couleur_carte couleur);
        Joueur_t(/* args */);
        ~Joueur_t();

        //Méthodes
        void initTirage();
        void choixCarte();
        void tirage();
};

Joueur_t::Joueur_t(Couleur_carte couleur){
}

Joueur_t::~Joueur_t(){
}



#endif