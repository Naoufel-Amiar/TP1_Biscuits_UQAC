#include "Commande.h"


Commande* NewCommande(
    std::string Source,
    std::string Destinataire)
{
    Commande* Co = new Commande;

    Co->Source = Source;
    Co->destinataire = Destinataire;

    // Pas encore de biscuit dans cette commande.
    Co->Biscuit_suivant = nullptr;

    // Le lien vers le client destinataire
    // sera etabli plus tard.
    Co->Destinataire = nullptr;

    // Pas encore de commande suivante.
    Co->suivant = nullptr;

    return Co;
}


void ADD_Commande(
    Commande* Liste_Commandes,
    std::string Source,
    std::string Destinataire)
{
    if (Liste_Commandes == nullptr)
    {
        Liste_Commandes = NewCommande(Source, Destinataire);
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


void Rm_Commande(Commande* Liste_Commandes)
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

        Ptr_Actuel->Biscuit_suivant = nullptr;

        delete Ptr_Actuel;

        Ptr_Actuel = Ptr_Suivant;
    }
}