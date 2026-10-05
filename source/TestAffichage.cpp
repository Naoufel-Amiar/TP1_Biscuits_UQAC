#include "ListeCommandes.h"

// ---------------------------------------------------------
// TEMPORAIRE
//
// Construit manuellement une liste chainee permettant
// de tester les commandes ? et $ sans utiliser charger().
// ---------------------------------------------------------
void ListeCommandes::creerDonneesTest()
{
    // =========================
    // CLIENTS
    // =========================

    Client* tremblay = new Client;
    tremblay->nom = "Tremblay";
    tremblay->numero = 125;
    tremblay->rue = "RueLavoie";
    tremblay->premiereCommande = nullptr;
    tremblay->suivant = nullptr;

    Client* gagnon = new Client;
    gagnon->nom = "Gagnon";
    gagnon->numero = 42;
    gagnon->rue = "RueSaintJean";
    gagnon->premiereCommande = nullptr;
    gagnon->suivant = nullptr;

    Client* bouchard = new Client;
    bouchard->nom = "Bouchard";
    bouchard->numero = 18;
    bouchard->rue = "BoulevardTalon";
    bouchard->premiereCommande = nullptr;
    bouchard->suivant = nullptr;

    Client* fortin = new Client;
    fortin->nom = "Fortin";
    fortin->numero = 73;
    fortin->rue = "RueCartier";
    fortin->premiereCommande = nullptr;
    fortin->suivant = nullptr;

    // Chaine des clients.
    premierClient = tremblay;
    tremblay->suivant = gagnon;
    gagnon->suivant = bouchard;
    bouchard->suivant = fortin;

    // =========================
    // COMMANDE 1
    // Tremblay -> Gagnon
    // Chocolat 5
    // Vanille 2
    // =========================

    Commande* commande1 = new Commande;
    commande1->destinataire = "Gagnon";
    commande1->suivante = nullptr;

    Biscuit* chocolat1 = new Biscuit;
    chocolat1->type = "Chocolat";
    chocolat1->quantite = 5;

    Biscuit* vanille1 = new Biscuit;
    vanille1->type = "Vanille";
    vanille1->quantite = 2;

    chocolat1->suivant = vanille1;
    vanille1->suivant = nullptr;

    commande1->premierBiscuit = chocolat1;
    tremblay->premiereCommande = commande1;

    // =========================
    // COMMANDE 2
    // Tremblay -> Bouchard
    // Chocolat 3
    // Erable 4
    // =========================

    Commande* commande2 = new Commande;
    commande2->destinataire = "Bouchard";
    commande2->suivante = nullptr;

    Biscuit* chocolat2 = new Biscuit;
    chocolat2->type = "Chocolat";
    chocolat2->quantite = 3;

    Biscuit* erable1 = new Biscuit;
    erable1->type = "Erable";
    erable1->quantite = 4;

    chocolat2->suivant = erable1;
    erable1->suivant = nullptr;

    commande2->premierBiscuit = chocolat2;
    commande1->suivante = commande2;

    // =========================
    // COMMANDE 3
    // Gagnon -> Fortin
    // Vanille 10
    // Chocolat 1
    // =========================

    Commande* commande3 = new Commande;
    commande3->destinataire = "Fortin";
    commande3->suivante = nullptr;

    Biscuit* vanille2 = new Biscuit;
    vanille2->type = "Vanille";
    vanille2->quantite = 10;

    Biscuit* chocolat3 = new Biscuit;
    chocolat3->type = "Chocolat";
    chocolat3->quantite = 1;

    vanille2->suivant = chocolat3;
    chocolat3->suivant = nullptr;

    commande3->premierBiscuit = vanille2;
    gagnon->premiereCommande = commande3;

    // =========================
    // COMMANDE 4
    // Bouchard -> Tremblay
    // Erable 6
    // Vanille 3
    // =========================

    Commande* commande4 = new Commande;
    commande4->destinataire = "Tremblay";
    commande4->suivante = nullptr;

    Biscuit* erable2 = new Biscuit;
    erable2->type = "Erable";
    erable2->quantite = 6;

    Biscuit* vanille3 = new Biscuit;
    vanille3->type = "Vanille";
    vanille3->quantite = 3;

    erable2->suivant = vanille3;
    vanille3->suivant = nullptr;

    commande4->premierBiscuit = erable2;
    bouchard->premiereCommande = commande4;

    // =========================
    // COMMANDE 5
    // Fortin -> Fortin
    // Chocolat 4
    // =========================

    Commande* commande5 = new Commande;
    commande5->destinataire = "Fortin";
    commande5->suivante = nullptr;

    Biscuit* chocolat4 = new Biscuit;
    chocolat4->type = "Chocolat";
    chocolat4->quantite = 4;
    chocolat4->suivant = nullptr;

    commande5->premierBiscuit = chocolat4;
    fortin->premiereCommande = commande5;
}