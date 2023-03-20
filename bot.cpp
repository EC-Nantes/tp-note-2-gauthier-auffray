#include "bot.hpp"
#include "random"

//Méthodes
void Bot_t::choixCarte(std::vector<Joueur_t*> v_joueurs, CouleurCarte_t* couleur, TypeAction_t* action, int* nbCases) {
    std::cout << "[Bot] Choix d'une carte : \n";
    srand (time(NULL)); //init seed
    int choix = rand() % 5 + 1; //nb entre 1 et 5 compris
    m_active_carte = mv_cartes[choix - 1];
    *action = m_active_carte->getTypeAction();
    *nbCases = m_active_carte->getNbCase();
    std::cout << "Carte " << choix << " - " << *m_active_carte;
    mv_cartes.erase(mv_cartes.begin() + (choix - 1)); //On supprime la carte de notre jeu

    //CHOIX ACTIONS SI CARTE NEUTRE
    choix = 0;
    if(m_active_carte->getCouleur() == NEUTRE_C){
        //AVANCER
        if(m_active_carte->getTypeAction() == AVANCER){
            std::cout << "[BOT] Choix de la tortue a avancer : \n";
            srand (time(NULL)); //init seed
            int choix = rand() % 5 + 1; //nb entre 1 et 5 compris

            switch(choix){
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
            std::cout << "[BOT] Choix action DERNIER : \n";
            srand (time(NULL)); //init seed
            int choix = rand() % 2 + 1; //nb entre 1 et 5 compris

            //1 TORTUE AU CHOIX
            if(choix == 1){
                std::cout << "[BOT] Choix de la couleur a avancer : \n";
                *action = AVANCER;
                srand (time(NULL)); //init seed
                int choix = rand() % 5 + 1; //nb entre 1 et 5 compris

                switch(choix){
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
                    std::cout << "[BOT] Deplacement des tortues suivantes de 1 case :\n";
                }
                else {
                    std::cout << "[BOT] Deplacement des tortues suivantes de 2 cases :\n";
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
            std::cout << "Erreur type action.\n";
        }   
    }//fin NEUTRE_C
    else { //CARTE non NEUTRE
        *couleur = m_active_carte->getCouleur();
        *nbCases = m_active_carte->getNbCase();
        std::cout << "Pas de choix d'action supplementaire a effectuer\n";
    }
}
