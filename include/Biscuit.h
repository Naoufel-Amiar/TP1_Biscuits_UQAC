#ifndef BISCUIT_H
#define BISCUIT_H

#include <string>
#include <vector>

struct Biscuit
{
    std::string type;
    int quantite;
    Biscuit* suivant;
};

class Clients
{

    std::string Nom;
    std::string numero_Rue;
    std::string Rue;
    
public:
    Clients (std::string Nom, std::string numero_Rue, std::string Rue) :
        Nom(Nom),
        numero_Rue(numero_Rue),
        Rue(Rue)
    {
    }

    std::string getNom()
    {
        return Nom;
    }

    std::string getNumeroRue()
    {
        return numero_Rue;
    }

    std::string getRue()
    {
        return Rue;
    }
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
