#include <iostream>
#include <fstream>
#include <string>

<<<<<<< Updated upstream:ProjetBiscuitJNT.cpp
#include "ListeCommandes.h"
=======
#include <iostream>

#include "include/ListeCommandes.h"
>>>>>>> Stashed changes:main.cpp




void crée_class_clients(){
    std::cout << "\n===== TEST1 =====" << std::endl;
    std::ifstream fichier_client("data/CLIENTS.txt");

    std::string nom;
    std::string numero_Rue;
    std::string rue;

    while (std::getline(fichier_client, nom)){

        

        //std::getline(fichier_client, nom);
        std::getline(fichier_client, numero_Rue);
        std::getline(fichier_client, rue);

        Clients client(nom, numero_Rue, rue);
       


        std::cout << "Client :" << std::endl;
        std::cout << "Nom : " << client.getNom() << std::endl;
        std::cout << "Numero rue : " << client.getNumeroRue() << std::endl;
        std::cout << "Rue : " << client.getRue() << std::endl;

        }
        fichier_client.close();
    }   


void  crée_class_commandes(){

    std::cout << "\n===== TEST2 =====" << std::endl;
    std::ifstream fichier_commande("data/COMMANDES.txt");
    
    std::string Particulier;
    std::string Vandeur;
    

    while (std::getline(fichier_commande, Particulier)){
        std::getline(fichier_commande, Vandeur);
        
        std::vector<std::string> numero_couki;
        std::vector<int> nombre_couki;
        std::string biscuit;
        int quantite;
        while (fichier_commande >> biscuit)
        {
            if (biscuit == "&")
            {
                std::getline(fichier_commande, biscuit);
                break;
            }
            fichier_commande >> quantite;
            numero_couki.push_back(biscuit);
            nombre_couki.push_back(quantite);
        }
        Commandesclient commandesclient (Particulier, Vandeur, numero_couki, nombre_couki);

        std::cout << "commandesclient :" << std::endl;
        std::cout << "Particulier : " << commandesclient.getParticulier() << std::endl;
        std::cout << "Vandeur: " << commandesclient.getVandeur() << std::endl;
        std::cout << "numero_couki : ";
        for (const std::string& numero : commandesclient.getnumero_couki())
        {
            std::cout << numero << " ";
        }
        std::cout << std::endl;
        std::cout << "nombre_couki : ";
        for (int nombre : commandesclient.getnombre_couki())
        {
            std::cout << nombre << " ";
        }
        std::cout << std::endl;
    }    
    fichier_commande.close();

}

int main (int argc, char* argv[])
{
<<<<<<< Updated upstream:ProjetBiscuitJNT.cpp

    std::cout << "HELLO WORLD" << std::endl;
=======
    crée_class_clients();
    crée_class_commandes();
    
   
  

>>>>>>> Stashed changes:main.cpp
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

<<<<<<< Updated upstream:ProjetBiscuitJNT.cpp
    return 0;
}
=======
    std::cout << "bbbbbbbbbb" << std::endl;
    return 0;
}


>>>>>>> Stashed changes:main.cpp
