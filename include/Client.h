#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Commande.h"

struct Client
{
    std::string nom;
    int numero;
    std::string Rue;

    Commande* CommandeAssociee;
    Client* suivant;
};

Client* NewClient(
    std::string Name,
    int Num,
    std::string Rue
);

void ADD_Client(
    Client* Liste_Clients,
    std::string Name,
    int Num,
    std::string Rue
);

void DelListClient(Client* Liste_Clients);

#endif