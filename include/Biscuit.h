#ifndef BISCUIT_H
#define BISCUIT_H

#include <string>

struct Commande;

struct Biscuit
{
    // Nom/type du biscuit.
    std::string nom;

    // Quantite commandee.
    int quantite;

    // Commande a laquelle appartient le biscuit.
    Commande* commandeAssociee;

    // Biscuit suivant dans la liste chainee.
    Biscuit* suivant;
};


Biscuit* NewBiscuit(
    std::string Name,
    int Quantite
);


void ADD_Biscuit(
    Biscuit* Liste_Biscuits,
    std::string Name,
    int Quantite
);


void Rm_Biscuit(
    Biscuit* Liste_Biscuits
);

#endif