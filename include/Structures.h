#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>

namespace std{

struct Client
{
    string nom;
    int numero;
    string Rue;

    Commande* CommandeAssociee;
    Client* suivant;
};

struct Commande
{
    string Source;
    string destinataire;

    Biscuit* Biscuit_suivant;
    Client* Destinataire;
    Commande* suivant;
};

struct Biscuit
{
    string nom;
    int quantite;
    
    Commande* commandeAssociee;
    Biscuit* suivant;
};


}






#endif