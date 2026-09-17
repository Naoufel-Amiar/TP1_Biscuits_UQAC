#ifndef LISTE_COMMANDES_H
#define LISTE_COMMANDES_H

#include <string>
#include "Client.h"

class ListeCommandes
{
private:
    Client* premierClient;

    Client* trouverClient(const std::string& nom);
    void libererBiscuits(Biscuit* biscuit);
    void libererCommandes(Commande* commande);

public:
    ListeCommandes();
    ~ListeCommandes();

    void ajouterClient(const std::string& nom, int numero, const std::string& rue);
    void supprimerClient(const std::string& nom);

    // TODO : definir les parametres necessaires pour l'ajout d'une commande.
    void ajouterCommande();

    void afficherCommandes(const std::string& nomClient);
    void afficherBiscuitPopulaire();

    void charger(const std::string& fichierClients,
                 const std::string& fichierCommandes);

    void sauvegarder(const std::string& fichierClients,
                     const std::string& fichierCommandes);
};

#endif
