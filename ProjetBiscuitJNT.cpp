#include <iostream>

#include "ListeCommandes.h"
#include "TransTerminal.h"

int main(int argc, char* argv[])
{
    // Le programme doit recevoir le fichier
    // TRANSACTIONS en argument.
    if (argc < 2)
    {
        std::cout
            << "Erreur : fichier TRANSACTIONS manquant."
            << std::endl;

        std::cout
            << "Utilisation : ProjetBiscuitJNT.exe TRANSACTIONS.txt"
            << std::endl;

        return 1;
    }

    // Structure principale contenant les clients,
    // commandes et biscuits.
    ListeCommandes liste;

    // Le terminal interprete les operations
    // contenues dans TRANSACTIONS.txt.
    TransTerminal terminal(liste);

    terminal.executer(
        argv[1]
    );


    std::cout << std::endl;
    std::cout << "===== TEST SUPPRESSION MILIEU =====" << std::endl;

    liste.supprimerClient("Thomas Bouchard");

    std::cout << std::endl;
    std::cout << "Verification client :" << std::endl;

    liste.afficherCommandes("Thomas Bouchard");

    std::cout << std::endl;
    std::cout << "Verification biscuit populaire :" << std::endl;

    liste.afficherBiscuitPopulaire();

    std::cout << std::endl;
    std::cout << "===== TEST SUPPRESSION TETE =====" << std::endl;

    liste.supprimerClient("Alexandre Gagnon");

    std::cout << "Verification client supprime :" << std::endl;
    liste.afficherCommandes("Alexandre Gagnon");

    std::cout << "Verification client restant :" << std::endl;
    liste.afficherCommandes("Camille Roy");


    std::cout << std::endl;
    std::cout << "===== TEST SUPPRESSION FIN =====" << std::endl;

    liste.supprimerClient("Julien Fortin");

    std::cout << "Verification client supprime :" << std::endl;
    liste.afficherCommandes("Julien Fortin");

    std::cout << "Verification client restant :" << std::endl;
    liste.afficherCommandes("Camille Roy");


    std::cout << std::endl;
    std::cout << "===== TEST CLIENT INEXISTANT =====" << std::endl;

    liste.supprimerClient("Dark Vador");
    return 0;
}