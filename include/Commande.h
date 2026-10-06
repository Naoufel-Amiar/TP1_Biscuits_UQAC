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


class Commandesclient
{
private:
    std::string Particulier;
    std::string Vandeur;
    std::vector<std::string> numero_couki;
    std::vector<int> nombre_couki;
public:

    Commandesclient (std::string Particulier, std::string Vandeur, std::vector<std::string> numero_couki, std::vector<int> nombre_couki) :
        Particulier(Particulier),
        Vandeur(Vandeur),
        numero_couki(numero_couki),
        nombre_couki(nombre_couki)
    {
    }
    std::string getParticulier()
    {
        return Particulier;
    }

    std::string getVandeur()
    {
        return Vandeur;
    }

    std::vector<std::string> getnumero_couki()
    {
        return numero_couki;
    }
    
    std::vector<int> getnombre_couki()
    {
        return nombre_couki;
    }

};

#endif
