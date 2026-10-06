#ifndef COMMANDE_H
#define COMMANDE_H

#include "Structures.h"
#include <string>

namespace std{

Commande* NewCommande (std::string Source, std::string Destinataire);

void ADD_Commande (Commande* &Liste_Commandes, std::string Source, std::string Destinataire);

void Rm_Commande (Commande* &Liste_Commandes);

}

#endif
