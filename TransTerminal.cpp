#include "TransTerminal.h"

#include <fstream>
#include <iostream>
#include <string>


// CONSTRUCTEUR

TransTerminal::TransTerminal(
    ListeCommandes& listeCommandes)
    : liste(listeCommandes)
{
}


// EXECUTION DU FICHIER DE TRANSACTIONS

void TransTerminal::executer(
    const std::string& fichierTransactions)
{
    std::ifstream fichier(
        fichierTransactions
    );

    if (!fichier.is_open())
    {
        std::cout
            << "Erreur : impossible d'ouvrir "
            << fichierTransactions
            << std::endl;

        return;
    }

    std::string operation;

    // Lecture des operations jusqu'a la fin du fichier.
    while (fichier >> operation)
    {
        // O : OUVERTURE DES FICHIERS
        // O CLIENTS COMMANDES


        if (operation == "O")
        {
            std::string fichierClients;
            std::string fichierCommandes;

            fichier
                >> fichierClients
                >> fichierCommandes;

            std::cout
                << "\n===== TRANSACTION O ====="
                << std::endl;

            liste.charger(
                "../data/" + fichierClients,
                "../data/" + fichierCommandes
            );
        }


        // S : SAUVEGARDE
        // S CLIENTS COMMANDES

        else if (operation == "S")
        {
            std::string fichierClients;
            std::string fichierCommandes;

            fichier
                >> fichierClients
                >> fichierCommandes;

            std::cout
                << "\n===== TRANSACTION S ====="
                << std::endl;

            liste.sauvegarder(
                "../data/" + fichierClients,
                "../data/" + fichierCommandes
            );
        }


        // + : AJOUT D'UN CLIENT
        // + C N A

        else if (operation == "+")
        {
            std::string nom;
            int numero;
            std::string rue;

            fichier
                >> nom
                >> numero
                >> rue;

            std::cout
                << "\n===== TRANSACTION + ====="
                << std::endl;

            liste.ajouterClient(
                nom,
                numero,
                rue
            );

            std::cout
                << "Client ajoute : "
                << nom
                << std::endl;
        }


        // - : SUPPRESSION D'UN CLIENT
        // - X

        else if (operation == "-")
        {
            std::string nom;

            fichier >> nom;

            std::cout
                << "\n===== TRANSACTION - ====="
                << std::endl;

            liste.supprimerClient(
                nom
            );
        }


        // ? : AFFICHAGE DES COMMANDES D'UN CLIENT
        // ? X

        else if (operation == "?")
        {
            std::string nom;

            fichier >> nom;

            std::cout
                << "\n===== TRANSACTION ? ====="
                << std::endl;

            liste.afficherCommandes(
                nom
            );
        }


        // $ : BISCUIT LE PLUS POPULAIRE

        else if (operation == "$")
        {
            std::cout
                << "\n===== TRANSACTION $ ====="
                << std::endl;

            liste.afficherBiscuitPopulaire();
        }


        // = : AJOUT D'UNE COMMANDE
        //
        // = X Y B1 X1 B2 X2 ... &

        else if (operation == "=")
        {
            std::string source;
            std::string destinataire;

            fichier
                >> source
                >> destinataire;

            std::cout
                << "\n===== TRANSACTION = ====="
                << std::endl;

            Commande* commande =
                liste.ajouterCommande(
                    source,
                    destinataire
                );

            // Lecture des biscuits jusqu'a &
            std::string biscuit;

            while (fichier >> biscuit)
            {
                // & termine la commande.
                if (biscuit == "&")
                {
                    break;
                }

                int quantite;

                fichier >> quantite;

                // Si la commande n'a pas pu etre creee,
                // ajouterBiscuit ne fera rien.
                liste.ajouterBiscuit(
                    commande,
                    biscuit,
                    quantite
                );
            }

            if (commande != nullptr)
            {
                std::cout
                    << "Commande ajoutee : "
                    << source
                    << " -> "
                    << destinataire
                    << std::endl;
            }
        }


        // # : CHIFFRE D'AFFAIRES TOTAL

        else if (operation == "#")
        {
            liste.Chiffre_affaire();
        }

        else
        {
            std::cout
                << "Erreur : operation inconnue : "
                << operation
                << std::endl;
        }
    }

    fichier.close();
}