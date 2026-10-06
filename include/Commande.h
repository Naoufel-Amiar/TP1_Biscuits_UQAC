#ifndef COMMANDE_H
#define COMMANDE_H

#include "Structures.h"
#include <string>

namespace std{

Commande* NewCommande (string Source, string Destinataire);

void ADD_Commande (Commande* Liste_Commandes, string Source, string Destinataire);

void Rm_Commande (Commande* Liste_Commandes);

}

#endif
