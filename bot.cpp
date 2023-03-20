#include "bot.hpp"
#include "random"
#include <string>

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
            std::cout << "[BOT] Choix de la tortue a avancer : ";
            std::string couleurString;
            srand (time(NULL)); //init seed
            int choix = rand() % 5 + 1; //nb entre 1 et 5 compris

            switch(choix){
                case 1:
                    *couleur = ROUGE_C;
                    couleurString = "Rouge";
                    break;
                case 2:
                    *couleur = BLEU_C;
                    couleurString = "Bleu";
                    break;
                case 3:
                    *couleur = VERT_C;
                    couleurString = "Vert";
                    break;
                case 4:
                    *couleur = JAUNE_C;
                    couleurString = "Jaune";
                    break;
                case 5:
                    *couleur = VIOLET_C;
                    couleurString = "Violet";
                    break;
                default:
                    couleurString = "Error";
                    std::cout << "Erreur choix couleurs !!! \n";
            }
            std::cout << couleurString << "\n";
        }
        //RECULER
        else if(m_active_carte->getTypeAction() == RECULER){
            std::cout << "[BOT] Choix la couleur a reculer : ";
            std::string couleurString;
            srand(time(NULL)); //init seed
            int choix = rand() % 5 + 1; //nb entre 1 et 5 compris

            switch(choix){
                case 1:
                    *couleur = ROUGE_C;
                    couleurString = "Rouge";
                    break;
                case 2:
                    *couleur = BLEU_C;
                    couleurString = "Bleu";
                    break;
                case 3:
                    *couleur = VERT_C;
                    couleurString = "Vert";
                    break;
                case 4:
                    *couleur = JAUNE_C;
                    couleurString = "Jaune";
                    break;
                case 5:
                    *couleur = VIOLET_C;
                    couleurString = "Violet";
                    break;
                default:
                    couleurString = "Error";
                    std::cout << "Erreur choix couleurs !!! \n";
            }
            std::cout << couleurString << "\n";
        }
        //DERNIER
        else if (m_active_carte->getTypeAction() == DERNIER){ 
            std::cout << "[BOT] Choix action : ";
            srand (time(NULL)); //init seed
            int choix = rand() % 2 + 1; //nb entre 1 et 5 compris

            //1 TORTUE AU CHOIX
            if(choix == 1){
                std::cout << "UNE tortue\n";
                std::cout << "[BOT] Choix de la couleur a avancer : ";
                std::string couleurString;
                *action = AVANCER;
                srand (time(NULL)); //init seed
                int choix = rand() % 5 + 1; //nb entre 1 et 5 compris

                switch(choix){
                    case 1:
                        *couleur = ROUGE_C;
                        couleurString = "Rouge";
                        break;
                    case 2:
                        *couleur = BLEU_C;
                        couleurString = "Bleu";
                        break;
                    case 3:
                        *couleur = VERT_C;
                        couleurString = "Vert";
                        break;
                    case 4:
                        *couleur = JAUNE_C;
                        couleurString = "Jaune";
                        break;
                    case 5:
                        *couleur = VIOLET_C;
                        couleurString = "Violet";
                        break;
                    default:
                        couleurString = "Error";
                        std::cout << "Erreur choix couleurs !!! \n";
                }
                std::cout << couleurString << "\n";

            }
            //TOUTES LES DERNIERES TORTUES
            else {
                std::cout << "LES dernieres tourtues\n";
                *couleur = NEUTRE_C;    //Couple DERNIER + NEUTRE_C = Deplacer toutes les tortues case plus faible
                std::cout << "[BOT] Deplacement des tortues suivantes de ";
                std::cout << unsigned(m_active_carte->getNbCase()) << " case :\n";
                for (auto& joueur : v_joueurs){
                    std::cout << " - " << joueur->getCouleurS() << "\n";
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
    }
}
