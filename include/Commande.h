#ifndef COMMANDE_H
#define COMMANDE_H

#include <string>
#include "Biscuit.h"

struct Commande
{
    std::string destinataire;
    Biscuit* premierBiscuit;
    Commande* suivante;
};

#endif
