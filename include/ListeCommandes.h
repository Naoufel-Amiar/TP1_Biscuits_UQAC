#ifndef LISTE_COMMANDES_H
#define LISTE_COMMANDES_H

#include <string>
#include "Client.h"

class ListeCommandes
{
private:

    // Tete de la liste chainee des clients.
    Client* premierClient;

    // Recherche un client par son nom.
    Client* trouverClient(const std::string& nom);

    // Liberation memoire.
    void libererBiscuits(Biscuit* &Liste_biscuit);
    void libererCommandes(Commande* &Liste_Commandes);

public:

    ListeCommandes();
    ~ListeCommandes();

    // Gestion des clients.
    void ajouterClient(
        const std::string& nom,
        int numero,
        const std::string& rue
    );

    void supprimerClient(
        const std::string& nom
    );

    // Gestion des commandes.
    Commande* ajouterCommande(
        const std::string& source,
        const std::string& destinataire
    );

    void ajouterBiscuit(
        Commande* commande,
        const std::string& nom,
        int quantite
    );

    // Commande ? X
    void afficherCommandes(
        const std::string& nomClient
    );

    // Commande $
    void afficherBiscuitPopulaire();

    // Chargement depuis les fichiers texte.
    void charger(
        const std::string& fichierClients,
        const std::string& fichierCommandes
    );

    // Sauvegarde dans les fichiers texte.
    void sauvegarder(
        const std::string& fichierClients,
        const std::string& fichierCommandes
    );

    int Chiffre_affaire();
};

#endif