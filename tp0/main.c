#include <stdio.h>
#include <string.h>

// type énuméré booléen
enum boolean
{
    false,
    true
};
// typedef enum boolean {false, true} bool;
typedef enum boolean bool;

// Structure candidat : char mat[5] et char nom[10]
struct candidat
{
    char mat[5];
    char nom[10];
};

typedef struct candidat candidat;

// Saisie des n candidats dans une liste t
void remplir(candidat t[], int n)
{
    int i;
    printf("\n--- Remplissage -----------");
    for (i = 0; i < n; i++)
    {
        // lecture de mat
        printf("\nMatricule   : ");
        scanf("%4s", &t[i].mat);
        fflush(stdin);
        // lecture de nom
        printf("Nom candidat: ");
        scanf("%s", &t[i].nom);
        fflush(stdin);
    }
}

// Affichage des candidats
void afficher(candidat t[], int n)
{
    int i;
    printf("\n\n--- Affichage -------------");
    for (i = 0; i < n; i++)
    {
        printf("\nMatricule   : %s", t[i].mat);
        printf("\nNom candidat: : %s", t[i].nom);
        printf("\n");
    }
}

// version itérative
// recherche de mat dans une liste t de n candidats
// retourne vrai si mat existe dans t, sinon faux
bool existe1(candidat t[], int n, char mat[])
{
    // for ()

    return true;
}

/*
//version récursive
bool existe2 (...)
{
    return true;
}
*/

/*
//Remplir une liste t2 avec des candidats uniques se trouvant dans t1
//Déterminer aussi la taille de la nouvelle liste t2
//Utiliser la fonction existe1 ou existe2 pour éviter les doublons
void supprimer_doublons (...)
{
    //...
    printf("\n%d valeurs en double trouvee(s) et supprimee(s)", ...);
    printf("\nIl reste %d valeur(s) unique(s)", ...);
}
*/

int main()
{
    const int n1 = 6; // pour le besoin du test
    // Liste initiale des candidats (première alternative)
    // candidat t1[] = {{"100", "Wadii"}, {"200", "Youssef"},
    //                  {"300", "Abir"},  {"300", "Abir"},
    //				   {"400", "Syrine"},{"100", "Wadii"}};

    candidat t1[n1];
    candidat t2[n1]; // liste finale sans doublons
    int n2 = 0;      // taille de la liste finale t2
    // Remplissage de la liste t1 (deuxième alternative)
    remplir(t1, n1);
    // Affichage de la liste initiale t1 avec doublons
    afficher(t1, n1);
    // Suppression des doublons

    // Affichage de la liste finale t2 sans doublons
}
