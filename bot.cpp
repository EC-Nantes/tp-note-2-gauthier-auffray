#include "bot.hpp"
#include "random"

//Méthodes
void Bot_t::choixCarte(std::vector<Joueur_t*> v_joueurs, CouleurCarte_t* couleur, TypeAction_t* action, int* nbCases) {
    std::cout << "Le bot choisis une carte : \n";
    srand (time(NULL)); //init seed
    int choix = rand() % 5 + 1; //nb entre 1 et 5 compris
    m_active_carte = mv_cartes[choix - 1];
    std::cout << "[Selection] Carte " << choix << " - " << *m_active_carte << "\n";
    //mv_cartes.erase(mv_cartes.begin() + (choix - 1)); //On supprime la carte de notre jeu
}
