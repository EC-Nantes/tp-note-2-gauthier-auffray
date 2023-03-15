#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include "carte.hpp"
#include "joueur.hpp"

class Plateau_t{

    private:
        std::vector<Carte_t*> mv_pioche;
        std::vector<Joueur_t*> mv_joueurs;
        std::vector<std::vector<Joueur_t*>> mv_cases;
        
    public:
        Plateau_t() {}  // contructor
        ~Plateau_t() {
            for(auto& pItem : mv_pioche){  
                delete pItem;
            }
            mv_pioche.clear();
        }

        //Méthodes
        void initPioche();
        Carte_t* tirerCarte();
        // void initTirage();
        // void action(Joueur_t);
};


#endif