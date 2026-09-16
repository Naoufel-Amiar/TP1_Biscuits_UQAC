#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Commande.h"

struct Client
{
    std::string nom;
    int numero;
    std::string rue;

    Commande* premiereCommande;
    Client* suivant;
};

#endif
