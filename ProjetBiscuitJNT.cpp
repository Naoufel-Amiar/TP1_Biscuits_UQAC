#include <iostream>

#include "ListeCommandes.h"
#include "TransTerminal.h"

int main(int argc, char* argv[])
{
    std::string fichierTransactions;
    // Le programme doit recevoir le fichier
    // TRANSACTIONS en argument.
    if (argc == 1) {
        fichierTransactions = "../data/TRANSACTIONS.txt";
        std::cout << "Aucun fichier fourni. Utilisation du fichier par defaut : " 
                  << fichierTransactions << std::endl;
    }

    else if (argc == 2) {
        fichierTransactions = argv[1];
    } 
    // S'il y a trop d'arguments, on affiche une erreur
    else {
        std::cerr << "Erreur : trop d'arguments." << std::endl;
        std::cerr << "Utilisation : " << argv[0] << " [chemin_du_fichier]" << std::endl;
        return 1;
    }

    // Structure principale contenant les clients,
    // commandes et biscuits.
    ListeCommandes liste;

    // Le terminal interprete les operations
    // contenues dans TRANSACTIONS.txt.
    TransTerminal terminal(liste);

    terminal.executer(
        fichierTransactions
    );

    return 0;
}
