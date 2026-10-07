#include <iostream>

#include "ListeCommandes.h"
#include "TransTerminal.h"

int main()
{
    // Le programme doit recevoir le fichier
    // TRANSACTIONS en argument.
    std::string fichierTransactions = "../data/TRANSACTIONS.txt";
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
