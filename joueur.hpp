#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include "carte.hpp"

enum Couleur_joueur {
        ROUGE_J,
        BLEU_J,
        VERT_J,
        JAUNE_J,
        VIOLET_J
    };

class Joueur_t{

    private:
        std::vector<Carte_t*> mv_cartes;
        Carte_t* m_active_carte;
       

    public:
        Joueur_t(Couleur_joueur couleur);
        Joueur_t(/* args */);
        ~Joueur_t();

        //Méthodes
        void addCarte(Carte_t* carte);
        void choixCarte();
        void tirage();
};



#endif