#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include "carte.hpp"
#include "joueur.hpp"

class Plateau_t{

    private:
        std::vector<Carte_t*> mv_pioche;
        std::vector<Joueur_t*> mv_joueurs;
        std::vector<std::vector<Joueur_t*>*> mv_cases;
        void initPioche();
        void initTirage();
        
    public:
        Plateau_t() = delete;  // contructor
        Plateau_t(uint8_t);
        ~Plateau_t();

        //Méthodes
        Carte_t* tirerCarte();
        bool find_tortue(Joueur_t*, uint16_t*, uint16_t*);
        std::vector<Joueur_t*>& getJoueurs() {return mv_joueurs;}

        friend std::ostream& operator<<(std::ostream&, Plateau_t&);
};


#endif