// #ifndef LSC_ACTEURS_H
// #define LSC_ACTEURS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un acteur
typedef struct acteur
{
    char nom[50];
    char pays[20];
    struct acteur *suiv;
} acteur;

// // Déclaration des fonctions
// acteur *creerActeur(char *nom, char *pays);
// void ajouterActeur(acteur **ptete, char *nom, char *pays);
// void afficherActeurs(acteur *tete);
// void libererActeurs(acteur **ptete);

// Creer un nouvel acteur
acteur *creerActeur(char *nom, char *pays)
{
    acteur *nouvelActeur = (acteur *)malloc(sizeof(acteur));
    strcpy(nouvelActeur->nom, nom);
    strcpy(nouvelActeur->pays, pays);
    nouvelActeur->suiv = NULL;
    return nouvelActeur;
}

// Ajouter un acteur  la fin de la liste
// si la liste est vide, ajouter le nouvel acteur au début
void ajouterActeur(acteur **ptete, char *nom, char *pays)
{
    acteur *p = creerActeur(nom, pays);
    if (*ptete == NULL)
        *ptete = p;
    else
    {
        acteur *fin = *ptete;
        while (fin->suiv != NULL)
            fin = fin->suiv;
        fin->suiv = p;
    }
}

// Afficher la liste des acteurs
void afficherActeurs(acteur *tete)
{
    acteur *temp = tete;
    while (temp != NULL)
    {
        printf("- Nom : %s, Pays : %s\n", temp->nom, temp->pays);
        temp = temp->suiv;
    }
}

// Libérer la mémoire de la liste des acteurs
void libererActeurs(acteur **ptete)
{
    acteur *temp;
    while (*ptete != NULL)
    {
        temp = *ptete;
        *ptete = (*ptete)->suiv;
        free(temp);
    }
}

// #endif // LSC_ACTEURS_H
