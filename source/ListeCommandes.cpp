#include "ListeCommandes.h"

#include <iostream>
#include <fstream>

ListeCommandes::ListeCommandes()
{
    premierClient = nullptr;
}

ListeCommandes::~ListeCommandes()
{
    // TODO : liberer toute la liste des clients et leurs commandes.
}

Client* ListeCommandes::trouverClient(const std::string& nom)
{
    // TODO
    return nullptr;
}

void ListeCommandes::libererBiscuits(Biscuit* biscuit)
{
    // TODO
}

void ListeCommandes::libererCommandes(Commande* commande)
{
    // TODO
}

void ListeCommandes::ajouterClient(const std::string& nom,
                                   int numero,
                                   const std::string& rue)
{
    // TODO
}

void ListeCommandes::supprimerClient(const std::string& nom)
{
    // TODO
}

void ListeCommandes::ajouterCommande()
{
    // TODO
}

void ListeCommandes::afficherCommandes(const std::string& nomClient)
{
    // TODO
}

void ListeCommandes::afficherBiscuitPopulaire()
{
    // TODO
}

void ListeCommandes::charger(const std::string& fichierClients,
                             const std::string& fichierCommandes)
{
    // TODO
}

void ListeCommandes::sauvegarder(const std::string& fichierClients,
                                 const std::string& fichierCommandes)
{
    // TODO
}
