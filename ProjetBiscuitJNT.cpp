#include <iostream>
#include <fstream>
#include <string>

#include "ListeCommandes.h"

int main(int argc, char* argv[])
{

    std::cout << "HELLO WORLD" << std::endl; //a suppr, simple test AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA  1111111111
    std::cout << "HELLO WORLD" << std::endl; //a suppr, simple test AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA  22222222222
    std::cout << "HELLO WORLD" << std::endl; //a suppr, simple test AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA   333333333333
    std::cout << "HELLO WORLD" << std::endl; //a suppr, simple test AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA   4444444444444



    if (argc < 2)
    {
        std::cout << "Erreur : fichier TRANSACTIONS manquant." << std::endl;
        return 1;
    }

    std::ifstream fichier(argv[1]);

    if (!fichier.is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir le fichier de transactions." << std::endl;
        return 1;
    }

    ListeCommandes liste;

    // TODO :
    // Lire les transactions O, S, +, -, =, ? et $
    // puis appeler les fonctions correspondantes.

    fichier.close();

    return 0;
}