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
    while(!plateau.tourDeJeu()) {
    }
    std::cout << "\n********** End tortuga **********\n";
    return 0;
}