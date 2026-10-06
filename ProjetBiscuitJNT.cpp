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


    std::cout << std::endl;
    std::cout << "===== TEST SUPPRESSION MILIEU =====" << std::endl;

    liste.supprimerClient("Thomas Bouchard");

    std::cout << std::endl;
    std::cout << "Verification client :" << std::endl;

    liste.afficherCommandes("Thomas Bouchard");

    std::cout << std::endl;
    std::cout << "Verification biscuit populaire :" << std::endl;

    liste.afficherBiscuitPopulaire();

    std::cout << std::endl;
    std::cout << "===== TEST SUPPRESSION TETE =====" << std::endl;

    liste.supprimerClient("Alexandre Gagnon");

    std::cout << "Verification client supprime :" << std::endl;
    liste.afficherCommandes("Alexandre Gagnon");

    std::cout << "Verification client restant :" << std::endl;
    liste.afficherCommandes("Camille Roy");


    std::cout << std::endl;
    std::cout << "===== TEST SUPPRESSION FIN =====" << std::endl;

    liste.supprimerClient("Julien Fortin");

    std::cout << "Verification client supprime :" << std::endl;
    liste.afficherCommandes("Julien Fortin");

    std::cout << "Verification client restant :" << std::endl;
    liste.afficherCommandes("Camille Roy");


    std::cout << std::endl;
    std::cout << "===== TEST CLIENT INEXISTANT =====" << std::endl;

    liste.supprimerClient("Dark Vador");
    return 0;
}