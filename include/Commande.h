#ifndef COMMANDE_H
#define COMMANDE_H

#include <string>
#include "Biscuit.h"

struct Client;

struct Commande
{
    // Nom du client qui effectue la commande.
    std::string Source;

    // Nom du destinataire.
    std::string destinataire;

    // Premier biscuit de la liste chainee de biscuits.
    Biscuit* Biscuit_suivant;

    // Pointeur vers le client destinataire.
    Client* Destinataire;

    // Commande suivante dans la liste chainee.
    Commande* suivant;
};

Commande* NewCommande(
    std::string Source,
    std::string Destinataire
);

void ADD_Commande(
    Commande* Liste_Commandes,
    std::string Source,
    std::string Destinataire
);

void Rm_Commande(Commande* Liste_Commandes);

#endif