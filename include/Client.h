#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Structures.h"


Client* NewClient (std::string Name, int Num, std::string Rue); //Création des maillons un a un, ne pas appeler

void ADD_Client (Client* &Liste_Clients, std::string Name, int Num, std::string Rue); //Création de la Liste Chainée des Clients,

void DelListClient (Client* &Liste_Clients); //destruction de la Liste Chainée


#endif
