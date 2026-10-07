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

Client* ListeCommandes::trouverClient(
    const std::string& nom)
{
    Client* courant = premierClient;

    while (courant != nullptr)
    {
        // Cas 1 : nom complet
        // Exemple : "Émilie Tremblay"
        if (courant->nom == nom)
        {
            return courant;
        }

        // Cas 2 : nom de famille uniquement
        // Exemple : "Tremblay"
        std::size_t positionEspace =
            courant->nom.find_last_of(' ');

        if (positionEspace != std::string::npos)
        {
            std::string nomFamille =
                courant->nom.substr(
                    positionEspace + 1
                );

            if (nomFamille == nom)
            {
                return courant;
            }
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

// =====================================================
// AJOUT D'UN CLIENT
// =====================================================

void ListeCommandes::ajouterClient(
    const std::string& nom,
    int numero,
    const std::string& rue)
{
    ADD_Client(
        premierClient,
        nom,
        numero,
        rue
    );
}


// =====================================================
// SUPPRESSION D'UN CLIENT
// Commande : - X
// =====================================================

void ListeCommandes::supprimerClient(
    const std::string& nom)
{
    Client* courant = trouverClient(nom);

    if (courant == nullptr)
    {
        std::cout
            << "Client introuvable."
            << std::endl;

        return;
    }

    // Recherche du maillon précédent.
    Client* precedent = nullptr;
    Client* recherche = premierClient;

    while (recherche != nullptr &&
           recherche != courant)
    {
        precedent = recherche;
        recherche = recherche->suivant;
    }

    // On conserve le maillon suivant.
    Client* suivant = courant->suivant;

    // Raccordement de la liste chaînée.
    if (precedent == nullptr)
    {
        premierClient = suivant;
    }
    else
    {
        precedent->suivant = suivant;
    }

    // Suppression des commandes du client.
    Rm_Commande(
        courant->CommandeAssociee
    );

    // Suppression du client.
    delete courant;

    std::cout
        << "Client supprime : "
        << nom
        << std::endl;
}


Commande* ListeCommandes::ajouterCommande(
    const string& source,
    const string& destinataire)
{
    // Recherche des deux clients.
    Client* clientSource =
        trouverClient(source);

    Client* clientDestinataire =
        trouverClient(destinataire);

    // Le client source doit etre inscrit.
    if (clientSource == nullptr)
    {
        std::cout
            << "Erreur : client source introuvable : "
            << source
            << std::endl;

        return nullptr;
    }

    // Le destinataire doit egalement etre inscrit.
    if (clientDestinataire == nullptr)
    {
        std::cout
            << "Erreur : client destinataire introuvable : "
            << destinataire
            << std::endl;

        return nullptr;
    }

    // ADD_Commande gere directement l'ajout
    // dans la liste chainee du client source.
    ADD_Commande(
        clientSource->CommandeAssociee,
        source,
        destinataire
    );

    // Recuperation de la commande qui vient
    // d'etre ajoutee a la fin de la liste.
    Commande* nouvelleCommande =
        clientSource->CommandeAssociee;

    while (nouvelleCommande->suivant != nullptr)
    {
        nouvelleCommande =
            nouvelleCommande->suivant;
    }

    // Association avec le client destinataire.
    nouvelleCommande->Destinataire =
        clientDestinataire;

    return nouvelleCommande;
}


void ListeCommandes::ajouterBiscuit(
    Commande* commande,
    const std::string& nom,
    int quantite)
{
    if (commande == nullptr)
    {
        return;
    }

    // ADD_Biscuit gere l'ajout dans
    // la liste chainee des biscuits.
    ADD_Biscuit(
        commande->Biscuit_suivant,
        nom,
        quantite
    );

    // Recuperation du biscuit qui vient
    // d'etre ajoute a la fin.
    Biscuit* nouveauBiscuit =
        commande->Biscuit_suivant;

    while (nouveauBiscuit->suivant != nullptr)
    {
        nouveauBiscuit =
            nouveauBiscuit->suivant;
    }

    // Association inverse biscuit -> commande.
    nouveauBiscuit->commandeAssociee =
        commande;
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
            stoi(numero),
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
    // =====================================================
    // Enregistrement des Comandes
    // =====================================================

    std::ofstream commandes(fichierCommandes);

    if (!commandes.is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir "
            << fichierCommandes << std::endl;
        return;
    }

    Client* client = premierClient;
    while (client != NULL){
        Commande* commande = client->CommandeAssociee;
        while (commande != NULL){

            commandes << commande->Source << std::endl;
            commandes << commande->destinataire << std::endl;

            Biscuit* biscuit = commande->Biscuit_suivant;
            while (biscuit != NULL){
                commandes << biscuit->nom << " " << biscuit->quantite << std::endl;
                biscuit = biscuit->suivant;
            }
            commande = commande->suivant;
            commandes << "&" << std::endl;
        }
        client = client->suivant;
    }
    commandes.close();





    // =====================================================
    // Enregistrement des Clients
    // =====================================================

    std::ofstream clients(fichierClients);

    if (!clients.is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir "
            << fichierClients << std::endl;
        return;
    }

    client = premierClient;

    while (client != NULL){
        clients << client->nom << std::endl;
        clients << client->numero << std::endl;
        clients << client->Rue << std::endl;
        client = client->suivant;
    }
    clients.close();

}