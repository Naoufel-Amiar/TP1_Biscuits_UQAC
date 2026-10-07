#include "ListeCommandes.h"
#include "Commande.h"
#include "Client.h"
#include "Biscuit.h"
#include "Structures.h"

#include <iostream>
#include <fstream>

using namespace std;


// =====================================================
// CONSTRUCTEUR
// =====================================================

ListeCommandes::ListeCommandes()
{
    premierClient = nullptr;
}


// =====================================================
// DESTRUCTEUR
// =====================================================

ListeCommandes::~ListeCommandes()
{
    // Sera complete avec la liberation memoire finale.
}


// =====================================================
// RECHERCHE D'UN CLIENT
// =====================================================

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


// =====================================================
// LIBERATION DES BISCUITS
// =====================================================

void ListeCommandes::libererBiscuits(Biscuit* biscuit)
{
    // Sera complete plus tard.
}


// =====================================================
// LIBERATION DES COMMANDES
// =====================================================

void ListeCommandes::libererCommandes(Commande* commande)
{
    // Sera complete plus tard.
}


// =====================================================
// AJOUT D'UN CLIENT
// =====================================================

void ListeCommandes::ajouterClient(
    const std::string& nom,
    int numero,
    const std::string& rue)
{
    // Creation du nouveau maillon Client.
    Client* nouveauClient =
        ADD_Client(nom, numero, rue);

    // Cas 1 : liste vide.
    if (premierClient == nullptr)
    {
        premierClient = nouveauClient;
        return;
    }

    // Cas 2 : ajout a la fin de la liste.
    Client* courant = premierClient;

    while (courant->suivant != nullptr)
    {
        courant = courant->suivant;
    }

    courant->suivant = nouveauClient;
}


// =====================================================
// SUPPRESSION D'UN CLIENT
// Commande : - X
// =====================================================

void ListeCommandes::supprimerClient(
    const std::string& nom)
{
    Client* courant = premierClient;
    Client* precedent = nullptr;

    // Recherche du client dans la liste chainee.
    while (courant != nullptr &&
        courant->nom != nom)
    {
        precedent = courant;
        courant = courant->suivant;
    }

    // Le client n'existe pas.
    if (courant == nullptr)
    {
        std::cout
            << "Client introuvable."
            << std::endl;

        return;
    }

    // Suppression des references vers le client
    // dans les commandes des autres clients.
    //
    // On ne supprime pas ces commandes :
    // on neutralise uniquement le pointeur vers
    // le Client qui va etre detruit.
    Client* clientParcouru = premierClient;

    while (clientParcouru != nullptr)
    {
        Commande* commandeParcourue =
            clientParcouru->CommandeAssociee;

        while (commandeParcourue != nullptr)
        {
            if (commandeParcourue->Destinataire ==
                courant)
            {
                commandeParcourue->Destinataire =
                    nullptr;
            }

            commandeParcourue =
                commandeParcourue->suivant;
        }

        clientParcouru =
            clientParcouru->suivant;
    }

    // Suppression de toutes les commandes
    // appartenant au client.
    Rm_Commande(
        courant->CommandeAssociee
    );

    // Cas 1 : suppression du premier client.
    if (precedent == nullptr)
    {
        premierClient =
            courant->suivant;
    }
    else
    {
        // Cas 2 : suppression au milieu
        // ou en fin de liste.
        precedent->suivant =
            courant->suivant;
    }

    delete courant;

    std::cout
        << "Client supprime : "
        << nom
        << std::endl;
}


// =====================================================
// AJOUT D'UNE COMMANDE
// Utilise notamment par : = X Y ...
// =====================================================

Commande* ListeCommandes::ajouterCommande(
    const std::string& source,
    const std::string& destinataire)
{
    // Recherche du client source.
    Client* clientSource =
        trouverClient(source);

    if (clientSource == nullptr)
    {
        std::cout
            << "Erreur : client source introuvable : "
            << source
            << std::endl;

        return nullptr;
    }

    // Recherche du client destinataire.
    Client* clientDestinataire =
        trouverClient(destinataire);

    if (clientDestinataire == nullptr)
    {
        std::cout
            << "Erreur : client destinataire introuvable : "
            << destinataire
            << std::endl;

        return nullptr;
    }

    // Creation de la nouvelle commande.
    Commande* nouvelleCommande =
        NewCommande(
            source,
            destinataire
        );

    // Association au Client destinataire.
    nouvelleCommande->Destinataire =
        clientDestinataire;

    // Premiere commande du client source.
    if (clientSource->CommandeAssociee ==
        nullptr)
    {
        clientSource->CommandeAssociee =
            nouvelleCommande;

        return nouvelleCommande;
    }

    // Sinon ajout a la fin de la liste
    // des commandes du client.
    Commande* courant =
        clientSource->CommandeAssociee;

    while (courant->suivant != nullptr)
    {
        courant = courant->suivant;
    }

    courant->suivant =
        nouvelleCommande;

    return nouvelleCommande;
}


// =====================================================
// AJOUT D'UN BISCUIT DANS UNE COMMANDE
// =====================================================

void ListeCommandes::ajouterBiscuit(
    Commande* commande,
    const std::string& nom,
    int quantite)
{
    // Impossible d'ajouter un biscuit
    // si la commande n'existe pas.
    if (commande == nullptr)
    {
        return;
    }

    Biscuit* nouveauBiscuit =
        NewBiscuit(
            nom,
            quantite
        );

    // Association du biscuit a sa commande.
    nouveauBiscuit->commandeAssociee =
        commande;

    // Premier biscuit.
    if (commande->Biscuit_suivant ==
        nullptr)
    {
        commande->Biscuit_suivant =
            nouveauBiscuit;

        return;
    }

    // Sinon ajout a la fin de la liste
    // des biscuits.
    Biscuit* courant =
        commande->Biscuit_suivant;

    while (courant->suivant != nullptr)
    {
        courant = courant->suivant;
    }

    courant->suivant =
        nouveauBiscuit;
}


// =====================================================
// AFFICHAGE DES COMMANDES D'UN CLIENT
// Commande : ? X
// =====================================================

void ListeCommandes::afficherCommandes(
    const std::string& nomClient)
{
    Client* client =
        trouverClient(nomClient);

    if (client == nullptr)
    {
        std::cout
            << "Client introuvable."
            << std::endl;

        return;
    }

    Commande* commande =
        client->CommandeAssociee;

    if (commande == nullptr)
    {
        std::cout
            << "Aucune commande pour ce client."
            << std::endl;

        return;
    }

    std::cout
        << "Commandes du client "
        << nomClient
        << " :"
        << std::endl;

    while (commande != nullptr)
    {
        std::cout
            << "Destinataire : "
            << commande->destinataire
            << std::endl;

        Biscuit* biscuit =
            commande->Biscuit_suivant;

        while (biscuit != nullptr)
        {
            std::cout
                << "  - "
                << biscuit->nom
                << " : "
                << biscuit->quantite
                << std::endl;

            biscuit =
                biscuit->suivant;
        }

        commande =
            commande->suivant;
    }
}


// =====================================================
// BISCUIT LE PLUS POPULAIRE
// Commande : $
// =====================================================

void ListeCommandes::afficherBiscuitPopulaire()
{
    std::string typePopulaire = "";
    int quantiteMax = 0;

    Client* client =
        premierClient;

    while (client != nullptr)
    {
        Commande* commande =
            client->CommandeAssociee;

        while (commande != nullptr)
        {
            Biscuit* biscuit =
                commande->Biscuit_suivant;

            while (biscuit != nullptr)
            {
                std::string typeRecherche =
                    biscuit->nom;

                int total = 0;

                // Recherche du total de ce type
                // de biscuit dans toutes les commandes.
                Client* clientRecherche =
                    premierClient;

                while (clientRecherche != nullptr)
                {
                    Commande* commandeRecherche =
                        clientRecherche->CommandeAssociee;

                    while (commandeRecherche != nullptr)
                    {
                        Biscuit* biscuitRecherche =
                            commandeRecherche->Biscuit_suivant;

                        while (biscuitRecherche != nullptr)
                        {
                            if (biscuitRecherche->nom ==
                                typeRecherche)
                            {
                                total +=
                                    biscuitRecherche->quantite;
                            }

                            biscuitRecherche =
                                biscuitRecherche->suivant;
                        }

                        commandeRecherche =
                            commandeRecherche->suivant;
                    }

                    clientRecherche =
                        clientRecherche->suivant;
                }

                if (total > quantiteMax)
                {
                    quantiteMax =
                        total;

                    typePopulaire =
                        typeRecherche;
                }

                biscuit =
                    biscuit->suivant;
            }

            commande =
                commande->suivant;
        }

        client =
            client->suivant;
    }

    if (typePopulaire == "")
    {
        std::cout
            << "Aucun biscuit vendu."
            << std::endl;

        return;
    }

    std::cout
        << "Biscuit le plus populaire : "
        << typePopulaire
        << std::endl;

    std::cout
        << "Quantite totale : "
        << quantiteMax
        << std::endl;

    // Chaque biscuit rapporte 1 dollar.
    std::cout
        << "Montant total recu : "
        << quantiteMax
        << " $"
        << std::endl;
}


// =====================================================
// CHARGEMENT DES FICHIERS
// Commande : O CLIENTS COMMANDES
// =====================================================

void ListeCommandes::charger(
    const std::string& fichierClients,
    const std::string& fichierCommandes)
{
    // =================================================
    // CHARGEMENT DES CLIENTS
    // =================================================

    std::ifstream clients(
        fichierClients
    );

    if (!clients.is_open())
    {
        std::cout
            << "Erreur : impossible d'ouvrir "
            << fichierClients
            << std::endl;

        return;
    }

    std::string nom;
    std::string numero;
    std::string rue;

    std::cout
        << "===== CHARGEMENT DES CLIENTS ====="
        << std::endl;

    while (std::getline(clients, nom))
    {
        if (!std::getline(
            clients,
            numero))
        {
            break;
        }

        if (!std::getline(
            clients,
            rue))
        {
            break;
        }

        ajouterClient(
            nom,
            std::stoi(numero),
            rue
        );

        std::cout
            << "Client : "
            << nom
            << std::endl;

        std::cout
            << "Adresse : "
            << numero
            << " "
            << rue
            << std::endl;

        std::cout
            << "------------------------"
            << std::endl;
    }

    clients.close();


    // =================================================
    // CHARGEMENT DES COMMANDES
    // =================================================

    std::ifstream commandes(
        fichierCommandes
    );

    if (!commandes.is_open())
    {
        std::cout
            << "Erreur : impossible d'ouvrir "
            << fichierCommandes
            << std::endl;

        return;
    }

    std::string expediteur;
    std::string destinataire;

    std::string biscuit;
    int quantite;

    std::cout << std::endl;

    std::cout
        << "===== CHARGEMENT DES COMMANDES ====="
        << std::endl;

    while (std::getline(
        commandes,
        expediteur))
    {
        // Deuxieme ligne :
        // client destinataire.
        if (!std::getline(
            commandes,
            destinataire))
        {
            break;
        }

        // Creation de la commande.
        Commande* commandeActuelle =
            ajouterCommande(
                expediteur,
                destinataire
            );

        std::cout
            << "Commande :"
            << std::endl;

        std::cout
            << "  Expediteur : "
            << expediteur
            << std::endl;

        std::cout
            << "  Destinataire : "
            << destinataire
            << std::endl;


        // Lecture des biscuits jusqu'a &
        while (commandes >> biscuit)
        {
            // Fin de la commande.
            if (biscuit == "&")
            {
                std::string finLigne;

                std::getline(
                    commandes,
                    finLigne
                );

                break;
            }

            // Lecture de la quantite.
            commandes >> quantite;

            // Utilisation de la methode commune
            // d'ajout d'un biscuit.
            ajouterBiscuit(
                commandeActuelle,
                biscuit,
                quantite
            );

            std::cout
                << "  - "
                << biscuit
                << " : "
                << quantite
                << std::endl;
        }

        std::cout
            << "------------------------"
            << std::endl;
    }

    commandes.close();
}


// =====================================================
// SAUVEGARDE
// Commande : S CLIENTS COMMANDES
// Thomas travaille sur cette partie.
// =====================================================

void ListeCommandes::sauvegarder(
    const std::string& fichierClients,
    const std::string& fichierCommandes)
{
    // Sera complete par Thomas.
}