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


Commande* ListeCommandes::ajouterCommande(
    const std::string& source,
    const std::string& destinataire)
{
    // Recherche du client qui effectue la commande.
    Client* clientSource = trouverClient(source);

    if (clientSource == nullptr)
    {
        std::cout << "Erreur : client source introuvable : "
            << source << std::endl;

        return nullptr;
    }

    // Creation de la nouvelle commande.
    Commande* nouvelleCommande =
        NewCommande(source, destinataire);

    // Association avec le client destinataire.
    nouvelleCommande->Destinataire =
        trouverClient(destinataire);

    // Premiere commande du client.
    if (clientSource->CommandeAssociee == nullptr)
    {
        clientSource->CommandeAssociee =
            nouvelleCommande;

        return nouvelleCommande;
    }

    // Sinon, ajout a la fin de sa liste de commandes.
    Commande* courant =
        clientSource->CommandeAssociee;

    while (courant->suivant != nullptr)
    {
        courant = courant->suivant;
    }

    courant->suivant = nouvelleCommande;

    return nouvelleCommande;
}

void ListeCommandes::afficherCommandes(const std::string& nomClient)
{
    Client* client = trouverClient(nomClient);

    if (client == nullptr)
    {
        std::cout << "Client introuvable." << std::endl;
        return;
    }

    Commande* commande = client->CommandeAssociee;

    if (commande == nullptr)
    {
        std::cout << "Aucune commande pour ce client." << std::endl;
        return;
    }

    std::cout << "Commandes du client "
        << nomClient
        << " :"
        << std::endl;

    while (commande != nullptr)
    {
        std::cout << "Destinataire : "
            << commande->destinataire
            << std::endl;

        Biscuit* biscuit = commande->Biscuit_suivant;

        while (biscuit != nullptr)
        {
            std::cout << "  - "
                << biscuit->nom
                << " : "
                << biscuit->quantite
                << std::endl;

            biscuit = biscuit->suivant;
        }

        commande = commande->suivant;
    }
}


void ListeCommandes::afficherBiscuitPopulaire()
{
    std::string typePopulaire = "";
    int quantiteMax = 0;

    Client* client = premierClient;

    while (client != nullptr)
    {
        Commande* commande = client->CommandeAssociee;

        while (commande != nullptr)
        {
            Biscuit* biscuit = commande->Biscuit_suivant;

            while (biscuit != nullptr)
            {
                std::string typeRecherche = biscuit->nom;
                int total = 0;

                Client* clientRecherche = premierClient;

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
                            if (biscuitRecherche->nom == typeRecherche)
                            {
                                total += biscuitRecherche->quantite;
                            }

                            biscuitRecherche = biscuitRecherche->suivant;
                        }

                        commandeRecherche = commandeRecherche->suivant;
                    }

                    clientRecherche = clientRecherche->suivant;
                }

                if (total > quantiteMax)
                {
                    quantiteMax = total;
                    typePopulaire = typeRecherche;
                }

                biscuit = biscuit->suivant;
            }

            commande = commande->suivant;
        }

        client = client->suivant;
    }

    if (typePopulaire == "")
    {
        std::cout << "Aucun biscuit vendu." << std::endl;
        return;
    }

    std::cout << "Biscuit le plus populaire : "
        << typePopulaire << std::endl;

    std::cout << "Quantite totale : "
        << quantiteMax << std::endl;

    std::cout << "Montant total recu : "
        << quantiteMax << " $" << std::endl;
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
        // Deuxieme ligne de la commande :
        // nom du destinataire.
        if (!std::getline(commandes, destinataire))
        {
            break;
        }

        // Creation de la commande dans la liste chainee.
        Commande* commandeActuelle =
            ajouterCommande(expediteur, destinataire);

        std::cout << "Commande :" << std::endl;

        std::cout << "  Expediteur : "
            << expediteur << std::endl;

        std::cout << "  Destinataire : "
            << destinataire << std::endl;


        // Lecture des biscuits jusqu'au caractere &
        while (commandes >> biscuit)
        {
            // & indique la fin de la commande.
            if (biscuit == "&")
            {
                std::string finLigne;
                std::getline(commandes, finLigne);

                break;
            }

            // Apres le nom du biscuit,
            // le fichier contient sa quantite.
            commandes >> quantite;


            // On ne peut ajouter les biscuits que si
            // la commande a correctement ete creee.
            if (commandeActuelle != nullptr)
            {
                Biscuit* nouveauBiscuit =
                    NewBiscuit(biscuit, quantite);

                // Association du biscuit avec sa commande.
                nouveauBiscuit->commandeAssociee =
                    commandeActuelle;


                // Premier biscuit de la commande.
                if (commandeActuelle->Biscuit_suivant == nullptr)
                {
                    commandeActuelle->Biscuit_suivant =
                        nouveauBiscuit;
                }
                else
                {
                    // Recherche du dernier biscuit.
                    Biscuit* biscuitCourant =
                        commandeActuelle->Biscuit_suivant;

                    while (biscuitCourant->suivant != nullptr)
                    {
                        biscuitCourant =
                            biscuitCourant->suivant;
                    }

                    // Ajout a la fin de la liste.
                    biscuitCourant->suivant =
                        nouveauBiscuit;
                }
            }


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