#include "Biscuit.h"

using namespace std;

Biscuit* NewBiscuit (string Name, int Quantite){
    Biscuit* Bi = new Biscuit;
    Bi->nom = Name;
    Bi->quantite = Quantite;
    Bi->commandeAssociee = NULL;
    Bi->suivant = NULL;
    return Bi;
}

void ADD_Biscuit (Biscuit* &Liste_Biscuits, string Name, int Quantite){
    if (Liste_Biscuits == NULL){
        Liste_Biscuits = NewBiscuit(Name, Quantite);
        return;
    }
    Biscuit* Ptr_Actuel;
    Ptr_Actuel = Liste_Biscuits;
    while (Ptr_Actuel->suivant != NULL){
        Ptr_Actuel = Ptr_Actuel->suivant;
    }
    Ptr_Actuel->suivant = NewBiscuit(Name, Quantite);
}

void Rm_Biscuit(Biscuit*& Liste_Biscuits)
{
    Biscuit* Ptr_Actuel = Liste_Biscuits;

    while (Ptr_Actuel != nullptr)
    {
        Biscuit* Ptr_Suivant = Ptr_Actuel->suivant;

        delete Ptr_Actuel;

        Ptr_Actuel = Ptr_Suivant;
    }

    Liste_Biscuits = nullptr;
}