#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include "carte.hpp"
#include "joueur.hpp"

class Plateau_t{

    private:
        std::vector<Carte_t*> mv_jeu_cartes;
        std::vector<Joueur_t*> mv_joueurs;
        std::vector<std::vector<Joueur_t*>> mv_cases;
        
    public:
        Plateau_t();
        ~Plateau_t();

        //Méthodes
        void initTirage();
        void action(Joueur_t);
};

Plateau_t::Plateau_t(){
}

Plateau_t::~Plateau_t(){
}



#endif