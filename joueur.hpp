#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include <string>
#include "carte.hpp"

enum Couleur_joueur {
    ROUGE_J,
    BLEU_J,
    VERT_J,
    JAUNE_J,
    VIOLET_J
};

class Joueur_t{

    protected:
        std::vector<Carte_t*> mv_cartes;
        Carte_t* m_active_carte; 
        Couleur_joueur m_couleur;

    public:
        //Constructeurs
        Joueur_t(Couleur_joueur couleur) {m_couleur = couleur;}
        Joueur_t() = delete;

        //Méthodes
        void addCarte(Carte_t* carte);
        virtual void choixCarte() = 0;
        void tirage(Carte_t* carte);
        Couleur_joueur getCouleur();
        std::string getCouleurS();
        std::vector<Carte_t*>& getCartes() {return mv_cartes;}
        friend std::ostream& operator<<(std::ostream&, Joueur_t&);
};



#endif