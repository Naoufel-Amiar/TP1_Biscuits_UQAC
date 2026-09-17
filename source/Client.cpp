#include "Client.h"

namespace std{

Client* NewClient (string Name, int Num, string Rue){
    Client* Cl = new Client;
    Cl->nom = Name;
    Cl->numero = Num;
    Cl->Rue = Rue;
    Cl->premiereCommande = NULL;
    Cl->suivant = NULL;
    return Cl;
}

void ADD (Client* Liste_Clients, string Name, int Num, string Rue){
    if (Liste_Clients == NULL){
        Liste_Clients = NewClient(Name, Num, Rue);
    }
    Client* Ptr_Actuel;
    Ptr_Actuel = Liste_Clients;
    while (Ptr_Actuel->suivant != NULL){
        Ptr_Actuel = Ptr_Actuel->suivant;
    }
    Ptr_Actuel->suivant = NewClient(Name, Num, Rue);
}


void DelListClient (Client* Liste_Clients){
    Client* Actu;
    Client* suivant = NULL;
    Actu = Liste_Clients;
    while (Actu != NULL){

            suivant = Actu->suivant;
            delete Actu;
            Actu = suivant;
    }
}




}



// Ce fichier pourra contenir des fonctions liees aux clients
// si le projet en a besoin par la suite.
