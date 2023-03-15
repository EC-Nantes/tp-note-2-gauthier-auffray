#include "bot.hpp"
#include "random"

//Méthodes
void Bot_t::choixCarte() {
    std::vector<Carte_t*>::const_iterator it_carte = mv_cartes.begin();
    char choix = 0;
    int i = 1;
    std::cout << "Le bot choisis une carte : \n";
    int choix = rand() % 5 + 1;
    m_active_carte = mv_cartes[choix - 1];
    std::cout << "[Selection] Carte " << choix << " - " << *m_active_carte << "\n";
    mv_cartes.erase(mv_cartes.begin() + (choix - 1)); //On supprime la carte de notre jeu
}
