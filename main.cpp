#include <iostream>
#include "carte.hpp"
#include "joueur.hpp"
#include "plateau.hpp"

int main() {
    std::cout << "*********************************\n";
    std::cout << "********* Start tortuga *********\n";
    std::cout << "*********************************\n\n";
    std::cout << "Selectionner le nombre de joueur reel (de 0 a 5): ";
    char choix;
    char char_endl;
    std::cin >> choix;
    char_endl = std::cin.get();
    while(choix < '0' || choix > '5' || char_endl != '\n') {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Saisie incorecte, saisir chiffre entre 0 et 5 : ";
        std::cin >> choix;
        char_endl = std::cin.get();
    }
    

    uint8_t nb_joueur;
    Plateau_t plateau(0);
    plateau.initPioche();

    // TypeAction_t AVANCER;
    // uint8_t case1 = 1;
    // uint8_t case2 = 2;

    // Joueur_t j1(ROUGE_J);
    // j1.addCarte(new Carte_t(ROUGE_C, AVANCER, case2));
    // j1.addCarte(new Carte_t(BLEU_C, AVANCER, case2));
    // j1.addCarte(new Carte_t(VERT_C, RECULER, case1));
    // j1.addCarte(new Carte_t(NEUTRE_C, DERNIER, case2));
    // j1.addCarte(new Carte_t(NEUTRE_C, AVANCER, case1));

    // j1.choixCarte();

    return 0;
}