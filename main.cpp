#include <iostream>
#include "carte.hpp"
#include "joueur.hpp"
#include "plateau.hpp"
#include "tests_unitaires.hpp"

int main() {
    Plateau_t plateau;
    plateau.initPioche();

    test_choix_carte();

    return 0;
}