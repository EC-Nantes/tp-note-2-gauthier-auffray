#include "bot.hpp"
#include "random"

//Méthodes
void Bot_t::choixCarte() {
    std::cout << "Le bot choisis une carte : \n";
    int choix = rand() % 5 + 1;
    m_active_carte = mv_cartes[choix - 1];
    std::cout << "[Selection] Carte " << choix << " - " << *m_active_carte << "\n";
    //mv_cartes.erase(mv_cartes.begin() + (choix - 1)); //On supprime la carte de notre jeu
}
