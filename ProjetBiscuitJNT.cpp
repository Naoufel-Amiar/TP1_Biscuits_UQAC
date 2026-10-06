/*
    ============================================================
    ANCIEN CODE RECUPERE DE MASTER - CONSERVE POUR REFERENCE
    ============================================================

#include <fstream>
#include <string>
#include <iostream>

#include "include/ListeCommandes.h"

void crée_class_clients()
{
    std::ifstream fichier_client("data/CLIENTS.txt");

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

void crée_class_commandes()
{
    std::ifstream fichier_commande("data/COMMANDES.txt");

    std::string Particulier;
    std::string Vandeur;

    while (std::getline(fichier_commande, Particulier))
    {
        std::getline(fichier_commande, Vandeur);

        std::vector<std::string> numero_couki;
        std::vector<int> nombre_couki;

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

            numero_couki.push_back(biscuit);
            nombre_couki.push_back(quantite);
        }

        Commandesclient commandesclient(
            Particulier,
            Vandeur,
            numero_couki,
            nombre_couki
        );
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

    fichier.close();

    std::cout << "bbbbbbbbbb" << std::endl;

    return 0;
}

    ============================================================
    FIN ANCIEN CODE MASTER
    ============================================================
*/


#include <iostream>

#include "ListeCommandes.h"
#include "Terminal.h"

int main()
{
    ListeCommandes liste;

    // TEMPORAIRE :
    // Creation manuelle des donnees de test.
    // Sera remplacee par le chargement des fichiers
    // CLIENTS.txt et COMMANDES.txt lors de l'integration finale.
    liste.creerDonneesTest();

    // Terminal permettant de tester les fonctions :
    // ? X : afficher les commandes d'un client
    // $   : afficher le biscuit le plus populaire
    lancerTerminal(liste);

    return 0;
}