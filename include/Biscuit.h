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


#endif
