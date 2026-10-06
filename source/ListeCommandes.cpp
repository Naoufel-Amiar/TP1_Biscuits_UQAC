#include "ListeCommandes.h"
#include "Commande.h"

#include <iostream>
#include <fstream>

using namespace std;

// Constructeur
ListeCommandes::ListeCommandes()
{
    premierClient = nullptr;
}

// Destructeur
ListeCommandes::~ListeCommandes()
{
    // TODO : liberer toute la liste des clients et leurs commandes.
}


// Recherche d'un client
Client* ListeCommandes::trouverClient(const string& nom)
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

void ListeCommandes::ajouterClient(
    const string& nom,
    int numero,
    const string& rue)
{
    // TODO
}


void ListeCommandes::supprimerClient(const string& nom)
{
    Client* courant = premierClient;
    Client* precedent = nullptr;

    // Recherche du client
    while (courant != nullptr && courant->nom != nom)
    {
        precedent = courant;
        courant = courant->suivant;
    }

    // Client non trouve
    if (courant == nullptr)
    {
        cout << "Client introuvable." << endl;
        return;
    }

    // Suppression des commandes du client
    Rm_Commande(courant->CommandeAssociee);

    // Si le client est le premier de la liste
    if (precedent == nullptr)
    {
        premierClient = courant->suivant;
    }
    else
    {
        precedent->suivant = courant->suivant;
    }

    delete courant;

    cout << "Client supprime : "
        << nom
        << endl;
}

Commande* ListeCommandes::ajouterCommande(
    const string& source,
    const string& destinataire)
{
    // Recherche du client qui effectue la commande.
    Client* clientSource = trouverClient(source);

    if (clientSource == nullptr)
    {
        cout << "Erreur : client source introuvable : "
            << source << endl;

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

void ListeCommandes::afficherCommandes(const string& nomClient)
{
    // Recherche du client demande.
    Client* client = trouverClient(nomClient);

    // Le client n'existe pas dans la liste.
    if (client == nullptr)
    {
        cout << "Client introuvable." << endl;
        return;
    }

    // Recuperation de la premiere commande du client.
    Commande* commande = client->premiereCommande;

    // Le client existe mais n'a passe aucune commande.
    if (commande == nullptr)
    {
        cout << "Aucune commande pour ce client." << endl;
        return;
    }

    cout << "Commandes du client "
        << nomClient
        << " :"
        << endl;

    // Parcours de toutes les commandes du client.
    while (commande != nullptr)
    {
        cout << "Destinataire : "
            << commande->destinataire
            << endl;

        // Recuperation du premier biscuit de la commande.
        Biscuit* biscuit = commande->premierBiscuit;

        // Parcours de tous les biscuits de cette commande.
        while (biscuit != nullptr)
        {
            cout << "  - "
                << biscuit->nom
                << " : "
                << biscuit->quantite
                << endl;

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
    string typePopulaire = "";
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
                string typeRecherche = biscuit->nom;
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
        cout << "Aucun biscuit vendu." << endl;
        return;
    }

    cout << "Biscuit le plus populaire : "
        << typePopulaire << endl;

    cout << "Quantite totale : "
        << quantiteMax << endl;

    cout << "Montant total recu : "
        << quantiteMax << " $" << endl;
}
void ListeCommandes::charger(
    const string& fichierClients,
    const string& fichierCommandes)
{
    // =====================================================
    // CHARGEMENT DES CLIENTS
    // =====================================================

    ifstream clients(fichierClients);

    if (!clients.is_open())
    {
        cout << "Erreur : impossible d'ouvrir "
            << fichierClients << endl;
        return;
    }

    string nom;
    string numero;
    string rue;

    cout << "===== CHARGEMENT DES CLIENTS ====="
        << endl;

    while (getline(clients, nom))
    {
        if (!getline(clients, numero))
        {
            break;
        }

        if (!getline(clients, rue))
        {
            break;
        }

        ajouterClient(
            nom,
            stoi(numero),
            rue
        );

        cout << "Client : "
            << nom << endl;

        cout << "Adresse : "
            << numero << " "
            << rue << endl;

        cout << "------------------------"
            << endl;
    }

    clients.close();


    // =====================================================
    // CHARGEMENT DES COMMANDES
    // =====================================================

    ifstream commandes(fichierCommandes);

    if (!commandes.is_open())
    {
        cout << "Erreur : impossible d'ouvrir "
            << fichierCommandes << endl;
        return;
    }

    string expediteur;
    string destinataire;

    string biscuit;
    int quantite;

    cout << endl;
    cout << "===== CHARGEMENT DES COMMANDES ====="
        << endl;

    while (getline(commandes, expediteur))
    {
        // Deuxieme ligne de la commande :
        // nom du destinataire.
        if (!getline(commandes, destinataire))
        {
            break;
        }

        // Creation de la commande dans la liste chainee.
        Commande* commandeActuelle =
            ajouterCommande(expediteur, destinataire);

        cout << "Commande :" << endl;

        cout << "  Expediteur : "
            << expediteur << endl;

        cout << "  Destinataire : "
            << destinataire << endl;


        // Lecture des biscuits jusqu'au caractere &
        while (commandes >> biscuit)
        {
            // & indique la fin de la commande.
            if (biscuit == "&")
            {
                string finLigne;
                getline(commandes, finLigne);

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


            cout << "  - "
                << biscuit
                << " : "
                << quantite
                << endl;
        }

        cout << "------------------------"
            << endl;
    }

    commandes.close();
}


// Sauvegarde
void ListeCommandes::sauvegarder(
    const string& fichierClients,
    const string& fichierCommandes)
{
    // TODO
}


void ListeCommandes::sauvegarder(const std::string& fichierClients,
    const std::string& fichierCommandes)
{
    // TODO
}