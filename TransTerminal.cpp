#include "TransTerminal.h"

#include <fstream>
#include <iostream>
#include <string>


TransTerminal::TransTerminal(
    ListeCommandes& listeCommandes)
    : liste(listeCommandes)
{
}


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

    while (fichier >> operation)
    {
        // =============================================
        // O : OUVERTURE / CHARGEMENT
        // =============================================

        if (operation == "O")
        {
            std::string fichierClients;
            std::string fichierCommandes;

            fichier
                >> fichierClients
                >> fichierCommandes;

            liste.charger(
                fichierClients,
                fichierCommandes
            );
        }


        // =============================================
        // S : SAUVEGARDE
        // =============================================

        else if (operation == "S")
        {
            std::string fichierClients;
            std::string fichierCommandes;

            fichier
                >> fichierClients
                >> fichierCommandes;

            liste.sauvegarder(
                fichierClients,
                fichierCommandes
            );
        }


        // =============================================
        // $
        // BISCUIT LE PLUS POPULAIRE
        // =============================================

        else if (operation == "$")
        {
            liste.afficherBiscuitPopulaire();
        }


        // =============================================
        // Les autres operations seront ajoutees
        // juste apres.
        // =============================================

        else
        {
            std::cout
                << "Operation inconnue : "
                << operation
                << std::endl;
        }
    }

    fichier.close();
}