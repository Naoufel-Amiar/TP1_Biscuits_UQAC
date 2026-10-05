#include "Terminal.h"

#include <iostream>
#include <string>

// =========================================================
// TERMINAL - VERSION DE TRAVAIL
//
// Les commandes ? et $ sont fonctionnelles.
//
// Le terminal interactif sert actuellement a tester
// l'appel des fonctions de ListeCommandes.
//
// A l'integration finale, cette logique devra etre adaptee
// pour lire les operations depuis TRANSACTIONS.txt.
//
// Les commandes +, -, =, O et S seront raccordees
// aux fonctions developpees par les autres membres.
// =========================================================
void lancerTerminal(ListeCommandes& liste)
{
    std::string ligne;

    std::cout << "==================================" << std::endl;
    std::cout << "     TERMINAL BISCUITCO - TEST     " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Commandes disponibles :" << std::endl;
    std::cout << "? X  : afficher les commandes du client X" << std::endl;
    std::cout << "$    : afficher le biscuit le plus populaire" << std::endl;
    std::cout << "quit : quitter le terminal" << std::endl;

    std::cout << std::endl;

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, ligne);

        // Ligne vide : aucune operation.
        if (ligne == "")
        {
            continue;
        }

        // Fermeture du terminal de test.
        if (ligne == "quit")
        {
            std::cout << "Fermeture du terminal." << std::endl;
            break;
        }

        // -------------------------------------------------
        // COMMANDE $
        // -------------------------------------------------
        if (ligne == "$")
        {
            liste.afficherBiscuitPopulaire();
        }

        // -------------------------------------------------
        // COMMANDE ? X
        // -------------------------------------------------
        else if (ligne[0] == '?')
        {
            // Format attendu :
            // ? Tremblay

            if (ligne.length() <= 2 || ligne[1] != ' ')
            {
                std::cout << "Format invalide. Utiliser : ? NomClient"
                    << std::endl;
            }
            else
            {
                // Tout ce qui se trouve apres "? "
                // correspond au nom du client.
                std::string nomClient = ligne.substr(2);

                liste.afficherCommandes(nomClient);
            }
        }

        // -------------------------------------------------
        // AUTRE COMMANDE
        // -------------------------------------------------
        else
        {
            std::cout << "Commande inconnue." << std::endl;
        }

        std::cout << std::endl;
    }
}