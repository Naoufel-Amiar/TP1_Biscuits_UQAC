#include <iostream>

#include "ListeCommandes.h"
#include "Terminal.h"

int main()
{
    ListeCommandes liste;

    // Lecture des donnees depuis les fichiers texte.
    liste.charger("data/CLIENTS.txt", "data/COMMANDES.txt");


    std::cout << std::endl;
    std::cout << "===== TEST ? =====" << std::endl;

    liste.afficherCommandes("Alexandre Gagnon");


    std::cout << std::endl;
    std::cout << "===== TEST $ =====" << std::endl;

    liste.afficherBiscuitPopulaire();

    return 0;
}