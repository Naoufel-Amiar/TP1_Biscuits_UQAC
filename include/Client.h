#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Commande.h"

namespace std{

struct Client
{
    string nom;
    int numero;
    string Rue;

    Commande* premiereCommande;
    Client* suivant;
};

Client* NewClient (string Name, int Num, string Rue); //Création des maillons un a un, ne pas appeler

void ADD (Client* Liste_Clients, string Name, int Num, string Rue); //Création de la Liste Chainée des Clients,

void DelListClient (Client* Liste_Clients); //destruction de la Liste Chainée

}

#endif
