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
    CouleurCarte_t m_couleur;
    TypeAction_t m_typeAction;
    uint8_t m_nbCase;
public:
    Carte_t(CouleurCarte_t, TypeAction_t, uint8_t);  // constructor
    ~Carte_t(); // destructor

    //Getteurs
    CouleurCarte_t getCouleur() const {return m_couleur;}
    TypeAction_t getTypeAction() const {return m_typeAction;}
    uint8_t getNbCase() const {return m_nbCase;}

    //Setteurs
    void setCouleur(CouleurCarte_t c) {m_couleur = c;}
    void setTypeAction(TypeAction_t ta) {m_typeAction = ta;}
    void setNbCase(uint8_t nbc) {m_nbCase = nbc;}

    friend std::ostream& operator<<(std::ostream&, Carte_t&); //fonction pouvant etre appelé sans instanciation d'objet mais accès membres
};
#endif