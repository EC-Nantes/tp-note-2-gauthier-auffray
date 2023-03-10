#ifndef CARTE_HPP
#define CARTE_HPP

enum CouleurCarte_t {
    ROUGE,
    BLEU,
    VERT,
    JAUNE,
    VIOLET,
    NEUTRE,
};



class Carte_t
{
private:
    CouleurCarte_t couleur;
public:
    Carte_t();
    ~Carte_t();
};


#endif