#ifndef TRANS_TERMINAL_H
#define TRANS_TERMINAL_H

#include <string>
#include "ListeCommandes.h"

class TransTerminal
{
private:
    ListeCommandes& liste;

public:
    TransTerminal(ListeCommandes& listeCommandes);

    void executer(
        const std::string& fichierTransactions
    );
};

#endif