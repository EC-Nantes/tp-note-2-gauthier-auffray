#include "plateau.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
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
    mv_cases.push_back(&mv_joueurs);
    for(int i = 0; i < 9; i++) {
        std::vector<Joueur_t*>* tableau_joueur = new std::vector<Joueur_t*>;
        this->mv_cases.push_back(tableau_joueur);
    }
    this->initPioche();
    this->initTirage();
}

Plateau_t::~Plateau_t() {
    for(auto& pItem : mv_pioche) {  
        delete pItem;
    }
    mv_pioche.clear();
    for(auto& pItem : mv_joueurs) {  
        delete pItem;
    }
    mv_joueurs.clear();
    for(auto& pItem : mv_cases) {
        delete pItem;
    }
    mv_cases.clear();
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

void Plateau_t::initTirage() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            mv_joueurs[i]->addCarte(this->tirerCarte());
        }
    }
}

bool Plateau_t::find_tortue(Joueur_t* joueur, uint16_t* case_p, uint16_t* position) {
    Couleur_joueur to_find = joueur->getCouleur();
    bool to_return = false;
    for(uint16_t i = 0; i < mv_cases.size(); i++) {
        std::vector<Joueur_t*> pile_joueurs = *mv_cases[i];
        for(uint16_t j = 0; j < pile_joueurs.size(); j++) {
            if(to_find == pile_joueurs[j]->getCouleur()) {
                *case_p = i;
                *position = j;
                i = mv_cases.size();
                j = pile_joueurs.size();
                to_return = true;
            }
        }
    }
    return to_return;
}

std::vector<Joueur_t*> Plateau_t::getDerniers() {
    for(int i = 0; i < mv_cases.size(); i++) {
        if(mv_cases[i]->size() > 0) {
            std::vector<Joueur_t*> to_return = *(mv_cases[i]);
            return to_return;
        }
    }
    std::vector<Joueur_t*> error;
    return error;
}

bool Plateau_t::tourDeJeu() {
    for(int i = 0; i < mv_joueurs.size(); i++) {
        std::cout << "Au joueur " << mv_joueurs[i]->getCouleurS() << " de jouer !\n";
        CouleurCarte_t couleur;
        TypeAction_t typeAction;
        int nb_case;
        mv_joueurs[i]->choixCarte(this->getDerniers(), &couleur, &typeAction, &nb_case);
        bool win = mooveTortues(couleur, typeAction, nb_case);
        std::cout << *this;
        if(win) {
            std::vector<Joueur_t*> winners = *(mv_cases[9]);
            std::cout << "Le(s) joueur(s) ";
            for(int j = 0; j < winners.size(); j++) {
                std::cout << winners[j]->getCouleurS() << " ";
            }
            std::cout << "ont win !!!\n";
            return true;
        }
    }
    return false;
}

bool Plateau_t::mooveTortues(CouleurCarte_t couleur, TypeAction_t type, int nb_case) {
    //to do
    //Faire évoluer mv_cases en fonction des paramètres
    // checker si une tortue a gagner
    // si une tortue a gagner renvoyer true
    // sinon renvoyer false
    return false;
}

std::ostream& operator<<(std::ostream& o, Plateau_t& p) {
    std::cout << "Plateau : \n";
    for(int i = 0; i < p.mv_cases.size(); i++) {
        std::cout << "[Case " << i + 1 << "]\n";
        std::vector<Joueur_t*> pile_joueurs = *p.mv_cases[i];
        if(pile_joueurs.size() > 0) {
            for(int j = 0; j < pile_joueurs.size(); j++) {
                std::cout << "\tJoueur en position " << j + 1 << " : ";
                std::cout << *pile_joueurs[j];
            }
            std::cout << "\n";
        }
        else {
            std::cout << "Pas de joueur sur cette case\n";
        }
    }
    std::cout << "\n";
    return o;
}