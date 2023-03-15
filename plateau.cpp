#include "plateau.hpp"
#include <algorithm>
#include <iostream>
#include "joueurReel.hpp"
#include "bot.hpp"

Plateau_t::Plateau_t(uint8_t nb_joueur_reel) {
    int i = 0;
    for(i = 0; i < nb_joueur_reel; i++) {
        JoueurReel_t* joueur = new JoueurReel_t((Couleur_joueur)i);
        this->mv_joueurs.push_back(joueur);
    }
    for(i = nb_joueur_reel; i < 5; i++) {
        Bot_t* bot = new Bot_t((Couleur_joueur)i);
        this->mv_joueurs.push_back(bot);
    }
}

Plateau_t::~Plateau_t() {
    for(auto& pItem : mv_pioche){  
        delete pItem;
    }
    mv_pioche.clear();
    for(auto& pItem2 : mv_joueurs){  
        delete pItem2;
    }
    mv_joueurs.clear();
}

void Plateau_t::initPioche() {
    CouleurCarte_t couleur = CouleurCarte_t::ROUGE_C;
    TypeAction_t typeAction;
    for(int i = 0; i < 5; i++) {
        typeAction = TypeAction_t::AVANCER;
        Carte_t* carte = new Carte_t(couleur, typeAction, 2);
        mv_pioche.push_back(carte);
        for(int j = 0; j < 5; j++) {
            Carte_t* carte = new Carte_t(couleur, typeAction, 1);
            mv_pioche.push_back(carte);
        }
        typeAction = TypeAction_t::RECULER;
        for(int j = 0; j < 2; j++) {
            Carte_t* carte = new Carte_t(couleur, typeAction, 1);
            mv_pioche.push_back(carte);
        }
        couleur = static_cast<CouleurCarte_t>(i + 1);
    }
    couleur = CouleurCarte_t::NEUTRE_C;
    typeAction = TypeAction_t::DERNIER;
    for(int i = 0; i < 2; i++) {
        Carte_t* carte = new Carte_t(couleur, typeAction, 2);
        mv_pioche.push_back(carte);
    }
    for(int i = 0; i < 3; i++) {
        Carte_t* carte = new Carte_t(couleur, typeAction, 1);
        mv_pioche.push_back(carte);
    }
    typeAction = TypeAction_t::AVANCER;
    for(int i = 0; i < 5; i++) {
        Carte_t* carte = new Carte_t(couleur, typeAction, 1);
        mv_pioche.push_back(carte);
    }
    typeAction = TypeAction_t::RECULER;
    for(int i = 0; i < 2; i++) {
        Carte_t* carte = new Carte_t(couleur, typeAction, 1);
        mv_pioche.push_back(carte);
    }

    std::random_shuffle(mv_pioche.begin(), mv_pioche.end());
}

Carte_t* Plateau_t::tirerCarte() {
    Carte_t* to_return = mv_pioche.back();
    mv_pioche.pop_back();
    return to_return;
}