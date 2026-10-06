#ifndef BISCUIT_H
#define BISCUIT_H

#include <string>



class parfum_nombre {
    public:
    std::string type;
    int quantite;
    parfum_nombre* suivant;

    
    parfum_nombre(std::string t, int q) : 
    type(t), 
    quantite(q), 
    suivant(nullptr) 
    {
    }
};



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
    parfum_nombre* tete;        // Pour lachichage il faux le mettre en public 

public:
    Commandesclient (std::string Particulier, std::string Vandeur, parfum_nombre* TETE) :
        Particulier(Particulier),
        Vandeur(Vandeur),
        tete(TETE)
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
/*
    std::string getnumero_couki()
    {
        return numero_couki;
    }
    
    std::<int> getnombre_couki()
    {
        return nombre_couki;
    }
*/
};



#endif
