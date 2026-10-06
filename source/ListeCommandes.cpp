#include "ListeCommandes.h"

#include <iostream>
#include <fstream>


// Constructeur
ListeCommandes::ListeCommandes()
{
    premierClient = nullptr;
}


// Destructeur
ListeCommandes::~ListeCommandes()
{
    // Sera complete avec les listes chainees finales.
}


// Recherche d'un client
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


// Liberation des biscuits
void ListeCommandes::libererBiscuits(Biscuit* biscuit)
{
    // Sera complete plus tard.
}


// Liberation des commandes
void ListeCommandes::libererCommandes(Commande* commande)
{
    // Sera complete plus tard.
}

void ListeCommandes::ajouterClient(
    const std::string& nom,
    int numero,
    const std::string& rue)
{
    // Creation du nouveau maillon Client.
    Client* nouveauClient = NewClient(nom, numero, rue);

    // Cas 1 : la liste est vide.
    // Le nouveau client devient la tete de la liste.
    if (premierClient == nullptr)
    {
        premierClient = nouveauClient;
        return;
    }

    // Cas 2 : la liste contient deja des clients.
    // On se place sur la tete.
    Client* courant = premierClient;

    // On avance jusqu'au dernier client.
    while (courant->suivant != nullptr)
    {
        courant = courant->suivant;
    }

    // Le dernier client pointe maintenant
    // vers le nouveau client.
    courant->suivant = nouveauClient;
}


// Suppression client
void ListeCommandes::supprimerClient(const std::string& nom)
{
    // Sera adapte plus tard.
}


// Ajout commande
void ListeCommandes::ajouterCommande()
{
    // Sera adapte plus tard.
}


// Commande ? X
void ListeCommandes::afficherCommandes(const std::string& nomClient)
{
    // Temporaire tant que les listes chainees finales
    // ne sont pas integrees.
    std::cout << "Affichage des commandes de : "
        << nomClient << std::endl;
}


// Commande $
void ListeCommandes::afficherBiscuitPopulaire()
{
    // Temporaire tant que les listes chainees finales
    // ne sont pas integrees.
    std::cout << "Calcul du biscuit populaire." << std::endl;
}


void ListeCommandes::charger(
    const std::string& fichierClients,
    const std::string& fichierCommandes)
{
    // =====================================================
    // CHARGEMENT DES CLIENTS
    // =====================================================

    std::ifstream clients(fichierClients);

    if (!clients.is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir "
            << fichierClients << std::endl;
        return;
    }

    std::string nom;
    std::string numero;
    std::string rue;

    std::cout << "===== CHARGEMENT DES CLIENTS ====="
        << std::endl;

    while (std::getline(clients, nom))
    {
        if (!std::getline(clients, numero))
        {
            break;
        }

        if (!std::getline(clients, rue))
        {
            break;
        }

        ajouterClient(
            nom,
            std::stoi(numero),
            rue
        );

        std::cout << "Client : "
            << nom << std::endl;

        std::cout << "Adresse : "
            << numero << " "
            << rue << std::endl;

        std::cout << "------------------------"
            << std::endl;
    }

    clients.close();


    // =====================================================
    // CHARGEMENT DES COMMANDES
    // =====================================================

    std::ifstream commandes(fichierCommandes);

    if (!commandes.is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir "
            << fichierCommandes << std::endl;
        return;
    }

    std::string expediteur;
    std::string destinataire;

    std::string biscuit;
    int quantite;

    std::cout << std::endl;
    std::cout << "===== CHARGEMENT DES COMMANDES ====="
        << std::endl;

    while (std::getline(commandes, expediteur))
    {
        // Lecture du destinataire.
        if (!std::getline(commandes, destinataire))
        {
            break;
        }

        std::cout << "Commande :" << std::endl;

        std::cout << "  Expediteur : "
            << expediteur << std::endl;

        std::cout << "  Destinataire : "
            << destinataire << std::endl;

        // Lecture des biscuits de cette commande.
        while (commandes >> biscuit)
        {
            // & = fin de la commande actuelle.
            if (biscuit == "&")
            {
                // On termine la ligne contenant &.
                std::string finLigne;
                std::getline(commandes, finLigne);

                break;
            }

            // Le mot lu est le type de biscuit.
            // On lit ensuite sa quantite.
            commandes >> quantite;

            std::cout << "  - "
                << biscuit
                << " : "
                << quantite
                << std::endl;
        }

        std::cout << "------------------------"
            << std::endl;
    }

    commandes.close();
}


// Sauvegarde
void ListeCommandes::sauvegarder(
    const std::string& fichierClients,
    const std::string& fichierCommandes)
{
    // Sera complete plus tard.
}