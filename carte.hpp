#ifndef CARTE_HPP
#define CARTE_HPP

#include <cstdint>
#include <iostream>

enum CouleurCarte_t {
    ROUGE_C,
    BLEU_C,
    VERT_C,
    JAUNE_C,
    VIOLET_C,
    NEUTRE_C
};

enum TypeAction_t {
    AVANCER,
    RECULER,
    DERNIER
};

class Carte_t
{
private:
    CouleurCarte_t couleur;
    TypeAction_t typeAction;
    uint8_t nbCase;
public:
    Carte_t(CouleurCarte_t, TypeAction_t, uint8_t);  // constructor
    ~Carte_t(); // destructor

    friend std::ostream& operator<<(std::ostream&, Carte_t&); //fonction pouvant etre appelé sans instanciation d'objet mais accès membres
};




#endif