#include "joueurReel.hpp"
#include <string>

//Méthodes
void JoueurReel_t::choixCarte(std::vector<Joueur_t*> v_joueurs, CouleurCarte_t* couleur, TypeAction_t* action, int* nbCases) {
    std::vector<Carte_t*>::const_iterator it_carte = mv_cartes.begin();
    char choix = 0;
    int i = 1;
    
    //CHOIX CARTE
    std::cout << "Veuillez choisir une carte en tapant son numero : \n";
    for(it_carte; it_carte != mv_cartes.end(); it_carte++){
        std::cout << "Carte " << i << " - " << **it_carte;
        i++;
    }
    while ( (choix < '1') || (choix > '5') ){
        std::cin.clear();
        std::cout << "Vous devez entrer un numero de 1 a 5 : ";
        std::cin >> choix;
    }
    int iChoix = choix - 48;

    //MAJ carte active et arguments
    m_active_carte = mv_cartes[iChoix - 1];
    std::cout << "Carte " << choix << " - " << *m_active_carte;
    *action = m_active_carte->getTypeAction();
    *nbCases = m_active_carte->getNbCase();
    
    mv_cartes.erase(mv_cartes.begin() + (iChoix - 1)); //On supprime la carte de notre jeu

    //CHOIX ACTIONS SI CARTE NEUTRE
    choix = 0;
    if(m_active_carte->getCouleur() == NEUTRE_C){
        //AVANCER
        if(m_active_carte->getTypeAction() == AVANCER){
            std::cout << "Choisissez la couleur a avancer : \n";
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
            iChoix = choix - 48;

            switch(iChoix){
                case 1:
                    *couleur = ROUGE_C;
                    break;
                case 2:
                    *couleur = BLEU_C;
                    break;
                case 3:
                    *couleur = VERT_C;
                    break;
                case 4:
                    *couleur = JAUNE_C;
                    break;
                case 5:
                    *couleur = VIOLET_C;
                    break;
                default:
                    std::cout << "Erreur choix couleurs !!! \n";
            }
        }
        //RECULER
        else if(m_active_carte->getTypeAction() == RECULER){
            *couleur = m_active_carte->getCouleur();
        }
        //DERNIER
        else if (m_active_carte->getTypeAction() == DERNIER){ 
            std::cout << "Que souhaitez-vous faire ? \n";
            std::cout << "1 - Deplacer une tortue de mon choix \n";
            std::cout << "2 - Deplacer toutes les dernieres tortues\n";
            std::cin >> choix;
            while ( (choix < '1') || (choix > '2') ){
                std::cin.clear();
                std::cout << "Vous devez entrer soit 1 soit 2 : \n";
                std::cin >> choix;
            }
            //1 TORTUE AU CHOIX
            if(choix == '1'){
                std::cout << "Choisissez la couleur a avancer : \n";
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
                iChoix = choix - 48;

                switch(iChoix){
                    case 1:
                        *couleur = ROUGE_C;
                        break;
                    case 2:
                        *couleur = BLEU_C;
                        break;
                    case 3:
                        *couleur = VERT_C;
                        break;
                    case 4:
                        *couleur = JAUNE_C;
                        break;
                    case 5:
                        *couleur = VIOLET_C;
                        break;
                    default:
                        std::cout << "Erreur choix couleurs !!! \n";
                }
            }
            //TOUTES LES DERNIERES TORTUES
            else {
                *couleur = NEUTRE_C;    //Couple DERNIER + NEUTRE_C = Deplacer toutes les tortues case plus faible
                if(m_active_carte->getNbCase() == 1){
                    std::cout << "Deplacement des tortues suivantes de 1 case :\n";
                }
                else {
                    std::cout << "Deplacement des tortues suivantes de 2 cases :\n";
                }

                for (auto& joueur : v_joueurs){
                    switch(joueur->getCouleur()){
                    case ROUGE_C:
                        std::cout << " - ROUGE\n";
                        break;
                    case BLEU_C:
                        std::cout << " - BLEU\n";
                        break;
                    case VERT_C:
                        std::cout << " - VERT\n";
                        break;
                    case JAUNE_C:
                        std::cout << " - JAUNE\n";
                        break;
                    case VIOLET_C:
                        std::cout << " - VIOLET\n";
                        break;
                    default:
                        std::cout << "Erreur choix couleurs !!! \n";
                    }
                }
            }
        }//fin type_action
        //ERROR
        else {
            std::cout << "Erreur type action\n";
        }   
    }//fin NEUTRE_C
    else { //CARTE non NEUTRE
        *couleur = m_active_carte->getCouleur();
    }
}
