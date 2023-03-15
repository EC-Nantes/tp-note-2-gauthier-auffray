#include <iostream>
#include "carte.hpp"
#include "joueur.hpp"
#include "plateau.hpp"

int main() {
    Plateau_t plateau;
    plateau.initPioche();

    // TypeAction_t AVANCER;
    // uint8_t case1 = 1;
    // uint8_t case2 = 2;

    // Joueur_t j1(ROUGE_J);
    // j1.addCarte(new Carte_t(ROUGE_C, AVANCER, case1));
    // j1.addCarte(new Carte_t(BLEU_C, AVANCER, case2));
    // j1.addCarte(new Carte_t(VERT_C, RECULER, case1));
    // j1.addCarte(new Carte_t(JAUNE_C, DERNIER, case2));
    // j1.addCarte(new Carte_t(NEUTRE_C, AVANCER, case1));

    // j1.choixCarte();

    return 0;
}