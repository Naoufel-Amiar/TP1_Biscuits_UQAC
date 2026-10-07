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

    return 0;
}
