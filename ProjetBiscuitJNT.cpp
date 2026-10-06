#include <fstream>
#include <string>
#include <iostream>

#include "include/ListeCommandes.h"




void crée_class_clients()
{

    std::ifstream fichier_client("build/data/CLIENTS.txt");

    std::string nom;
    std::string numero_Rue;
    std::string rue;

    while (std::getline(fichier_client, nom))
    {
        std::getline(fichier_client, numero_Rue);
        std::getline(fichier_client, rue);

        Clients client(nom, numero_Rue, rue);
       
    }
        fichier_client.close();
}   

// Juste de l'afichage à ritierer avent randu 

/*
void afficherCommande(const Commandesclient& cmd)
{
    std::cout << "Client : " << cmd.Particulier << " | Vendeur : " << cmd.Vandeur << std::endl;
    std::cout << "Biscuits commandés :" << std::endl;

    parfum_nombre* courant = cmd.tete;

    if (courant == nullptr)
    {
        std::cout << "  (Aucun biscuit)" << std::endl;
    }

    while (courant != nullptr)
    {
        std::cout << "  - Parfum : " << courant->type << " | Quantite : " << courant->quantite << std::endl;
        courant = courant->suivant;
    }
    std::cout << "-----------------------------------" << std::endl;
}
*/

void  crée_class_commandes()
{
    std::ifstream fichier_commande("build/data/COMMANDES.txt");

    if (!fichier_commande.is_open()) 
    {
        std::cerr << "Erreur : Impossible d'ouvrir data/COMMANDES.txt !" << std::endl;
        return;
    }
    std::string Particulier;
    std::string Vandeur;
    
    while (std::getline(fichier_commande, Particulier))
        {
            std::getline(fichier_commande, Vandeur);
            
            parfum_nombre* tete = nullptr;
            parfum_nombre* queue = nullptr;
            std::string biscuit;
            int quantite;

            while (fichier_commande >> biscuit)
            {
                if (biscuit == "&")
                {
                    std::getline(fichier_commande, biscuit);
                    break;
                }
                fichier_commande >> quantite;
                parfum_nombre* nouveau = new parfum_nombre(biscuit, quantite);
                if (tete == nullptr)
                {
                    tete = nouveau;
                    queue = nouveau;
                }
                else 
                {
                    queue->suivant = nouveau;
                    queue = nouveau;
                }
            }
            Commandesclient commandesclient (Particulier, Vandeur, tete);
            afficherCommande(commandesclient);
        }
        fichier_commande.close();
}




int main(int argc, char* argv[])

{
    
    crée_class_clients();
    crée_class_commandes();

    if (argc < 2)
    {
        std::cout << "Erreur : fichier TRANSACTIONS manquant." << std::endl;
        return 1;
    }

    std::ifstream fichier(argv[1]);

    if (!fichier.is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir le fichier de transactions." << std::endl;
        return 1;
    }

    ListeCommandes liste;

    // TODO : lire les transactions O, S, +, -, =, ? et $
    // puis appeler les methodes correspondantes de ListeCommandes.

    fichier.close();
    return 0;
}




