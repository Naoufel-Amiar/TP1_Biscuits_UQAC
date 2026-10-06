#include <iostream>

#include "ListeCommandes.h"
#include "Terminal.h"

int main()
{
    ListeCommandes liste;

    // Lecture des donnees depuis les fichiers texte.
    liste.charger("data/CLIENTS.txt", "data/COMMANDES.txt");

    return 0;
}