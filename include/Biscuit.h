#ifndef BISCUIT_H
#define BISCUIT_H

#include <string>

struct Biscuit
{
    std::string nom;
    int quantite;
    
    Commande* commandeAssociee;
    Biscuit* suivant;
};

Biscuit* NewBiscuit (std::string Name, int Quantite);

void ADD_Biscuit (Biscuit* Liste_Biscuits, std::string Name, int Quantite);

void Rm_Biscuit (Biscuit* Liste_Biscuits);


#endif
