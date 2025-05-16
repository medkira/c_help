#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// partie déclarative
struct livre
{
    char titre[20];
    int qte;
};
typedef struct livre livre;

// définir la structure cellule (liv+suiv)
struct cellule
{
    livre liv;
    struct cellule *suiv;
};
// définir le type cellule
typedef struct cellule cellule;
// définir le type liste (cellule *)
typedef cellule *liste;
//--------------------------------------------------------------------

bool vide(liste lst) // bool vide (cellule * lst)
{
    // retourne true si la liste lst est vide, sinon false
    return lst == NULL;
}

//--------------------------------------------------------------------------------------

// Permet d'afficher la liste des livres
void affiche(liste lst)
{

    int nbtot = 0, nbliv = 0;
    if (vide(lst)) //(lst==NULL)
        printf("\n*** liste vide ***");
    else
    {
        printf("\n*** Liste de livres ***");
        while (!vide(lst))
        {
            printf("\nTitre : %s ", lst->liv.titre);
            printf("\t- Qte : %d ", lst->liv.qte);
            nbliv++;
            nbtot += lst->liv.qte;
            lst = lst->suiv;
        }
    }
    printf("\nLe nombre total de livres est     : %d", nbliv);
    printf("\nLe nombre total d'exemplaires est : %d", nbtot);
}

//--------------------------------------------------------------------

// retourne un ptr sur le livre intitulé titreliv, s'il existe dans lst,
// sinon NULL
liste recherche_livre(liste lst, char titreliv[])
{
    while (!vide(lst))

        if (strcmp(titreliv, lst->liv.titre) == 0)
            return lst;
}

//------------------------------------------------------------------------------------------

// Elle permet d'ajouter le livre unliv au début de la liste lst
// et retourner la nouvelle liste lst
// NB: La liste doit contenir des livres distincts (titre unique)
//     Si le livre unliv existe dans lst, alors mettre à jour la quantité
liste ajout_debut_1(liste lst, livre unliv)
{
    // version fonction (avec passage par valeur)
    liste p = recherche_livre(lst, unliv.titre);
    if (p != NULL) // unliv existe dans lis
        p->liv.qte += unliv.qte;
    else
    {

        liste p = (liste)malloc(sizeof(liste));
        p->liv = unliv;
        p->suiv = lst;
        lst = p;
    }

    return lst;
}

void ajout_debut_2()
{
    // version procédure (avec passage par référence)
}

//-----------------------------------------------------------------

// Elle permet de retourner le ptr de la dernière cellule dans lst
// Si la liste est vide, elle renvoie NULL
liste dernier_1(liste lst)
{
    // version récursive
}

liste dernier_2(liste lst)
{
    // version itérative
}

//------------------------------------------------------------------

// ajouter le livre unliv à la fin de la liste lst
// en utilisant la fonction ajout_debut
liste ajout_fin_1(liste lst, livre unliv)
{
}

void ajout_fin_2()
{
}

//--------------------------------------------------------------------

// retourne le nombre de livres en rupture de stock (qte = 0)
int indisponible(liste lst)
{
    int nb = 0;
    //...
    return nb;
}

//--------------------------------------------------------------------

// version récursive
// Supprime tous les livres indisponibles (en rupture de stock)
void suppr_indisponible_1()
{
}

//--------------------------------------------------------------------

// version itérative
void suppr_indisponible_2(liste *pl)
{
}

//--------------------------------------------------------------------

int main()
{
    int i, n;
    printf("\n*** Chargement des données ***");
    printf("\nDonner le nombre des livres : ");
    scanf("%d", &n);

    // ajouter n livres dans une liste lst
    for (i = 0; i < n; i++)
    {
        printf("\nDonner le titre    : ");
        //...
        printf("\nDonner la quantite : ");
        //...
    }

    printf("\n*** Liste initiale ***");
    //...

    printf("\n*** Dernier livre ***");
    //...

    // printf("\nLe nombre de livres en rupture de stock est %d ", ...);

    printf("\nSupprimer tous les livres en rupture de stock\n");
    //...

    printf("\n*** Liste des livres disponibles ***");
    //...
}
