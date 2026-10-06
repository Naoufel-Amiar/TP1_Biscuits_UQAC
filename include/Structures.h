#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>

struct Commande;
struct Biscuit;

struct Client
{
    std::string nom;
    int numero;
    std::string Rue;

    Commande* CommandeAssociee;
    Client* suivant;
};

struct Commande
{
    std::string Source;
    std::string destinataire;

    Biscuit* Biscuit_suivant;
    Client* Destinataire;
    Commande* suivant;
};

struct Biscuit
{
    std::string nom;
    int quantite;
    
    Commande* commandeAssociee;
    Biscuit* suivant;
};








#endif