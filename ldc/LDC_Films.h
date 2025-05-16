#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LSC_Acteurs.h"

// Structure pour représenter un film
// titre, realisateur, acteurs, suiv, prec
typedef struct film
{
    char titre[50];
    char realisateur[50];
    acteur *act;
    struct film *suiv;
    struct film *prec;
} film;

// Créer un nouveau film et retourner son pointeur
// Initialiser la liste des acteurs à NULL
film *creerFilm(char *titre, char realisateur[])
{
    film *p = (film *)malloc(sizeof(film));
    strcpy(p->titre, titre);
    strcpy(p->realisateur, realisateur);
    p->prec = NULL;
    p->suiv = NULL;
    p->act = NULL;
    return p;
}

// Ajouter un film à la fin de la liste tete: ajouterFilm
// utiliser la fonction creerFilm
void ajouterFilm(film **ptete, char *titre, char realisateur[])
{
    film *p = creerFilm(titre, realisateur);
    if (*ptete == NULL)
        *ptete = p;
    else
    {
        film *fin = *ptete;
        while (fin->suiv != NULL)
            fin = fin->suiv;
        fin->suiv = p;
        p->prec = fin;
    }
}

// Rechercher un film par son titre
film *rechercherFilm(film *tete, char *titre)
{
    film *temp = tete;
    while (temp != NULL)
    {
        if (strcmp(temp->titre, titre) == 0)
            return temp;
        temp = temp->suiv;
    }
    return NULL;
}

// Supprimer un film par son titre
// void supprimerFilm(...)

// Afficher la liste des films (avec ses acteurs)
void afficherFilms(film *tete)
{
    while (tete != NULL)
    {
        printf("Titre : %s, R�alisateur : %s \n", tete->titre, tete->realisateur);
        printf("Acteurs :\n");
        // Afficher la liste des acteurs
        afficherActeurs(tete->act);
        printf("\n");
        tete = tete->suiv;
    }
}

// Libérer la mémoire de la liste des films (avec ses acteurs)
// void libererFilms(...)
