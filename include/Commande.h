#ifndef COMMANDE_H
#define COMMANDE_H

#include "Client.h"
#include "Biscuit.h"

#include <string>

struct Commande
{
    std::string Source;
    std::string destinataire;

    Biscuit* Biscuit_suivant;
    Client* Destinataire;
    Commande* suivant;
};


#endif
