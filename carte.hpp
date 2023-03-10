#ifndef CARTE_HPP
#define CARTE_HPP

#include <cstdint>

enum CouleurCarte_t {
    ROUGE,
    BLEU,
    VERT,
    JAUNE,
    VIOLET,
    NEUTRE
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
};


#endif