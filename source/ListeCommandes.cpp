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


// Recherche un client dans la liste chainee a partir de son nom.
Client* ListeCommandes::trouverClient(const std::string& nom)
{
    Client* courant = premierClient;

    while (courant != nullptr)
    {
        if (courant->nom == nom)
        {
            return courant;
        }

        courant = courant->suivant;
    }

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


// ---------------------------------------------------------
// COMMANDE ? X
//
// Affiche toutes les commandes effectuees par le client X.
// ---------------------------------------------------------
void ListeCommandes::afficherCommandes(const std::string& nomClient)
{
    // Recherche du client demande.
    Client* client = trouverClient(nomClient);

    // Le client n'existe pas dans la liste.
    if (client == nullptr)
    {
        std::cout << "Client introuvable." << std::endl;
        return;
    }

    // Recuperation de la premiere commande du client.
    Commande* commande = client->premiereCommande;

    // Le client existe mais n'a passe aucune commande.
    if (commande == nullptr)
    {
        std::cout << "Aucune commande pour ce client." << std::endl;
        return;
    }

    std::cout << "Commandes du client "
        << nomClient
        << " :"
        << std::endl;

    // Parcours de toutes les commandes du client.
    while (commande != nullptr)
    {
        std::cout << "Destinataire : "
            << commande->destinataire
            << std::endl;

        // Recuperation du premier biscuit de la commande.
        Biscuit* biscuit = commande->premierBiscuit;

        // Parcours de tous les biscuits de cette commande.
        while (biscuit != nullptr)
        {
            std::cout << biscuit->type
                << " "
                << biscuit->quantite
                << std::endl;

            biscuit = biscuit->suivant;
        }

        commande = commande->suivante;
    }
}


// ---------------------------------------------------------
// COMMANDE $
//
// Recherche le type de biscuit le plus populaire et affiche
// le montant total recu pour ce type de biscuit.
// ---------------------------------------------------------
void ListeCommandes::afficherBiscuitPopulaire()
{
    std::string typePopulaire = "";
    int quantiteMax = 0;

    Client* client = premierClient;

    // Premier parcours :
    // on examine chaque type de biscuit existant.
    while (client != nullptr)
    {
        Commande* commande = client->premiereCommande;

        while (commande != nullptr)
        {
            Biscuit* biscuit = commande->premierBiscuit;

            while (biscuit != nullptr)
            {
                std::string typeRecherche = biscuit->type;
                int total = 0;

                // Deuxieme parcours :
                // on calcule la quantite totale de ce type
                // dans toutes les commandes.
                Client* clientRecherche = premierClient;

                while (clientRecherche != nullptr)
                {
                    Commande* commandeRecherche =
                        clientRecherche->premiereCommande;
                    while (commandeRecherche != nullptr)
                    {
                        Biscuit* biscuitRecherche =
                            commandeRecherche->premierBiscuit;

                        while (biscuitRecherche != nullptr)
                        {
                            if (biscuitRecherche->type == typeRecherche)
                            {
                                total += biscuitRecherche->quantite;
                            }
                            biscuitRecherche = biscuitRecherche->suivant;
                        }
                        commandeRecherche = commandeRecherche->suivante;
                    }
                    clientRecherche = clientRecherche->suivant;
                }
                // Nouveau maximum trouve.
                if (total > quantiteMax)
                {
                    quantiteMax = total;
                    typePopulaire = typeRecherche;
                }
                biscuit = biscuit->suivant;
            }
            commande = commande->suivante;
        }
        client = client->suivant;
    }
    if (typePopulaire == "")
    {
        std::cout << "Aucun biscuit vendu." << std::endl;
        return;
    }

    std::cout << "Biscuit le plus populaire : "
        << typePopulaire
        << std::endl;

    std::cout << "Quantite totale : "
        << quantiteMax
        << std::endl;

    std::cout << "Montant total recu : "
        << quantiteMax
        << " $"
        << std::endl;
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