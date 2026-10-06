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
    }
    Biscuit* Ptr_Actuel;
    Ptr_Actuel = Liste_Biscuits;
    while (Ptr_Actuel->suivant != NULL){
        Ptr_Actuel = Ptr_Actuel->suivant;
    }
    Ptr_Actuel->suivant = NewBiscuit(Name, Quantite);
}

void Rm_Biscuit (Biscuit* Liste_Biscuits){
    if (Liste_Biscuits == NULL){
        return;
    }
    Biscuit* Ptr_Actuel;
    Biscuit* Ptr_suivant = NULL;
    Ptr_Actuel = Liste_Biscuits;
    while (Ptr_Actuel != NULL){
        Ptr_suivant = Ptr_Actuel->suivant;
        delete Ptr_Actuel;
        Ptr_Actuel = Ptr_suivant;
    }
}