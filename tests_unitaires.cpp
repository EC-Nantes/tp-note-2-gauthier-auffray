#include "tests_unitaires.hpp"

void test_choix_carte(){
    std::cout << "//////// TEST CHOIX CARTE ////////\n";
    uint8_t case1 = 1;
    uint8_t case2 = 2;
    Joueur_t j1(ROUGE_J);
    j1.addCarte(new Carte_t(ROUGE_C, AVANCER, case2));
    j1.addCarte(new Carte_t(BLEU_C, AVANCER, case2));
    j1.addCarte(new Carte_t(VERT_C, RECULER, case1));
    j1.addCarte(new Carte_t(NEUTRE_C, DERNIER, case2));
    j1.addCarte(new Carte_t(NEUTRE_C, AVANCER, case1));
    j1.choixCarte();
}