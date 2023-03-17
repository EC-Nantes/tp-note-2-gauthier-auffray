#include "joueurReel.hpp"
#include <string>

//Méthodes
void JoueurReel_t::choixCarte(std::vector<Joueur_t*> v_joueurs, CouleurCarte_t* couleur, TypeAction_t* action, int* nbCases) {
    std::vector<Carte_t*>::const_iterator it_carte = mv_cartes.begin();
    char choix = 0;
    int i = 1;
    std::cout << "Veuillez choisir une carte en tapant son numero : \n";
    for(it_carte; it_carte != mv_cartes.end(); it_carte++){
        std::cout << "Carte " << i << " - " << **it_carte << "\n";
        i++;
    }
    while ( (choix < '1') || (choix > '5') ){
        std::cin.clear();
        std::cout << "Vous devez entrer un numero de 1 a 5 : \n";
        std::cin >> choix;
    }
    int iChoix = choix - 48;
    m_active_carte = mv_cartes[iChoix - 1];
    std::cout << "[Selection] Carte " << choix << " - " << *m_active_carte << "\n";
    mv_cartes.erase(mv_cartes.begin() + (iChoix - 1)); //On supprime la carte de notre jeu

    //2eme PHASE de CHOIX
    char choix = 0;
    if(m_active_carte->getCouleur() == NEUTRE_C){
        if(m_active_carte->getTypeAction() != DERNIER){
            std::cout << "Choisissez la couleur a deplacer : \n";
            std::cout << "1 - ROUGE \n";
            std::cout << "2 - BLEU \n";
            std::cout << "3 - VERT \n";
            std::cout << "4 - JAUNE \n";
            std::cout << "5 - VIOLET \n";
            std::cin >> choix;
            while ( (choix < '1') || (choix > '5') ){
                std::cin.clear();
                std::cout << "Vous devez entrer un numero de 1 a 5 : \n";
                std::cin >> choix;
            }
        }
        else { //DERNIER
            std::cout << "Que souhaitez-vous faire ? \n";
            std::cout << "1 - Deplacer une tortue de mon choix \n";
            std::cout << "2 - Deplacer toutes les tortues de la derniere case\n";
            std::cin >> choix;
            while ( (choix < '1') || (choix > '2') ){
                std::cin.clear();
                std::cout << "Vous devez entrer soit 1 soit 2 : \n";
                std::cin >> choix;
            }

            if(choix == '1'){

            }
        }
        
    }
    else {
        std::cout << "Pas de choix d'action supplementaire a effectuer.\n";
    }
}
