#include "Client.h"
#include "Commande.h"

using namespace std;

Client* NewClient(std::string Name, int Num, std::string Rue)
{
    Client* Cl = new Client;

    Cl->nom = Name;
    Cl->numero = Num;
    Cl->Rue = Rue;
    Cl->CommandeAssociee = NULL;
    Cl->suivant = NULL;
    return Cl;
}

void ADD_Client (Client* &Liste_Clients, string Name, int Num, string Rue){
    if (Liste_Clients == NULL){
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


void DelListClient (Client* &Liste_Clients){
    Client* Actu;
    Client* suivant = NULL;
    Commande* commandeActu;
    Actu = Liste_Clients;
    while (Actu != NULL){
            suivant = Actu->suivant;
            Rm_Commande(Actu->CommandeAssociee);
            delete Actu;
            Actu = suivant;
    }
    Liste_Clients = NULL;
}

