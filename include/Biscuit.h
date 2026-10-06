#ifndef BISCUIT_H
#define BISCUIT_H

#include <string>
#include "Structures.h"

namespace std{

Biscuit* NewBiscuit (string Name, int Quantite);

void ADD_Biscuit (Biscuit* Liste_Biscuits, string Name, int Quantite);

void Rm_Biscuit (Biscuit* Liste_Biscuits);

}

#endif
