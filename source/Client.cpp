#include "Client.h"


Client* NewClient(std::string Name, int Num, std::string Rue)
{
    Client* Cl = new Client;

    Cl->nom = Name;
    Cl->numero = Num;
    Cl->Rue = Rue;

    // Aucune commande associee au moment
    // de la creation du client.
    Cl->CommandeAssociee = nullptr;

    // Aucun client suivant pour le moment.
    Cl->suivant = nullptr;

    return Cl;
}


void ADD_Client(
    Client* Liste_Clients,
    std::string Name,
    int Num,
    std::string Rue)
{
    if (Liste_Clients == nullptr)
    {
        Liste_Clients = NewClient(Name, Num, Rue);
        return;
    }

    Client* Ptr_Actuel = Liste_Clients;

    while (Ptr_Actuel->suivant != nullptr)
    {
        Ptr_Actuel = Ptr_Actuel->suivant;
    }

    Ptr_Actuel->suivant = NewClient(Name, Num, Rue);
}


void DelListClient(Client* Liste_Clients)
{
    Client* Actu = Liste_Clients;

    while (Actu != nullptr)
    {
        Client* suivant = Actu->suivant;

        delete Actu;

        Actu = suivant;
    }
}