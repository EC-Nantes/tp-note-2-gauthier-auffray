#include "tests_unitaires.hpp"

void test_choix_carte(){
    std::cout << "//////// TEST CHOIX CARTE ////////\n";
    uint8_t case1 = 1;
    uint8_t case2 = 2;
    JoueurReel_t j1(ROUGE_J);
    j1.addCarte(new Carte_t(ROUGE_C, AVANCER, case2));
    j1.addCarte(new Carte_t(BLEU_C, AVANCER, case2));
    j1.addCarte(new Carte_t(VERT_C, RECULER, case1));
    j1.addCarte(new Carte_t(NEUTRE_C, DERNIER, case2));
    j1.addCarte(new Carte_t(NEUTRE_C, AVANCER, case1));
    // j1.choixCarte();

    std::cout << "//////// TOUR BOT ////////\n";
    Bot_t j2(ROUGE_J);
    j2.addCarte(new Carte_t(ROUGE_C, AVANCER, case2));
    j2.addCarte(new Carte_t(BLEU_C, AVANCER, case2));
    j2.addCarte(new Carte_t(VERT_C, RECULER, case1));
    j2.addCarte(new Carte_t(NEUTRE_C, DERNIER, case2));
    j2.addCarte(new Carte_t(NEUTRE_C, AVANCER, case1));
    // j2.choixCarte();
    // j2.choixCarte();
}

void test_find_tortues() {
    Plateau_t plateau(3);
    std::cout << plateau;
    uint16_t c;
    uint16_t p;
    std::vector<Joueur_t*> joueurs = plateau.getJoueurs();
    plateau.find_tortue(joueurs[4]->getCouleur(), &c, &p);
    std::cout << "Le joueur " << joueurs[4]->getCouleurS();
    std::cout << " est sur la case " << c << " a la position " << p +1<< "\n";
}

void test_get_derniers() {
    Plateau_t plateau(3);
    std::cout << plateau;
    std::vector<Joueur_t*> joueurs_2 = plateau.getDerniers();
    for(auto& temp : joueurs_2) {
        std::cout << *temp << "\n";
    }
}