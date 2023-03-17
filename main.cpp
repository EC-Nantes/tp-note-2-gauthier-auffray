#include <iostream>
#include <vector>
#include "carte.hpp"
#include "joueur.hpp"
#include "plateau.hpp"
#include "tests_unitaires.hpp"

int main() {
    //test_choix_carte();
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
    uint8_t nb_joueur = choix - '0';
    std::cout << "nb joueur reel : " << unsigned(nb_joueur) << "\n";
    Plateau_t plateau(nb_joueur);
    std::cout << plateau;
    uint16_t c;
    uint16_t p;
    std::vector<Joueur_t*> joueurs = plateau.getJoueurs();
    plateau.find_tortue(joueurs[4], &c, &p);
    std::cout << "Le joueur " << joueurs[4]->getCouleurS();
    std::cout << " est sur la case " << c << " a la position " << p +1<< "\n";

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