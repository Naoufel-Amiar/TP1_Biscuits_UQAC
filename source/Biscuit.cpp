#include "Biscuit.h"


Biscuit* NewBiscuit(
    std::string Name,
    int Quantite)
{
    Biscuit* Bi = new Biscuit;

    Bi->nom = Name;
    Bi->quantite = Quantite;

    // Le lien avec la commande sera etabli
    // lors du chargement des donnees.
    Bi->commandeAssociee = nullptr;

    // Aucun biscuit suivant pour le moment.
    Bi->suivant = nullptr;

    return Bi;
}


void ADD_Biscuit(
    Biscuit* Liste_Biscuits,
    std::string Name,
    int Quantite)
{
    if (Liste_Biscuits == nullptr)
    {
        Liste_Biscuits =
            NewBiscuit(Name, Quantite);

        return;
    }

    Biscuit* Ptr_Actuel = Liste_Biscuits;

    while (Ptr_Actuel->suivant != nullptr)
    {
        Ptr_Actuel = Ptr_Actuel->suivant;
    }

    Ptr_Actuel->suivant =
        NewBiscuit(Name, Quantite);
}


void Rm_Biscuit(Biscuit* Liste_Biscuits)
{
    Biscuit* Ptr_Actuel = Liste_Biscuits;

    while (Ptr_Actuel != nullptr)
    {
        Biscuit* Ptr_Suivant =
            Ptr_Actuel->suivant;

        Ptr_Actuel->commandeAssociee = nullptr;

        delete Ptr_Actuel;

        Ptr_Actuel = Ptr_Suivant;
    }
}