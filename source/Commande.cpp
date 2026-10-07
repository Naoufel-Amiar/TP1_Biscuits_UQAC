#include "Commande.h"
#include "Biscuit.h"

Commande* NewCommande(
    std::string Source,
    std::string Destinataire)
{
    Commande* Co = new Commande;

    Co->Source = Source;
    Co->destinataire = Destinataire;
    Co->Biscuit_suivant = nullptr;
    Co->Destinataire = nullptr;
    Co->suivant = nullptr;

    return Co;
}


void ADD_Commande(
    Commande*& Liste_Commandes,
    std::string Source,
    std::string Destinataire)
{
    if (Liste_Commandes == nullptr)
    {
        Liste_Commandes =
            NewCommande(Source, Destinataire);

        return;
    }

    Commande* Ptr_Actuel = Liste_Commandes;

    while (Ptr_Actuel->suivant != nullptr)
    {
        Ptr_Actuel = Ptr_Actuel->suivant;
    }

    Ptr_Actuel->suivant =
        NewCommande(Source, Destinataire);
}


void Rm_Commande(
    Commande*& Liste_Commandes)
{
    Commande* Ptr_Actuel = Liste_Commandes;

    while (Ptr_Actuel != nullptr)
    {
        Commande* Ptr_Suivant =
            Ptr_Actuel->suivant;

        Ptr_Actuel->Destinataire = nullptr;

        Rm_Biscuit(
            Ptr_Actuel->Biscuit_suivant
        );

        delete Ptr_Actuel;

        Ptr_Actuel = Ptr_Suivant;
    }

    Liste_Commandes = nullptr;
}