#include <stdio.h>
#include "LDC_Films.h"

void afficherMenu()
{
    printf("\n------ Menu ------\n");
    printf("1. Ajouter un film\n");
    printf("2. Ajouter un acteur au film\n");
    printf("3. Afficher tous les films\n");
    printf("4. Supprimer un film\n");
    printf("5. Rechercher un film\n");
    printf("6. Quitter\n");
    printf("----------\n");
    printf("Choix : ");
}

int main()
{
    film *films = NULL;
    int choix;
    char titre[50], realisateur[50], nom[50], pays[20];

    do
    {
        afficherMenu();
        scanf("%d", &choix);
        fflush(stdin); // vider la zone tampon
        // ou bien getchar(); // Pour consommer le saut de ligne

        switch (choix)
        {
        case 1: // Ajouter un film
            printf("\nTitre du film : ");
            printf("Realisateur      : ");
            printf("Realisateur : ");
            scanf("%s", realisateur);
            ajouterFilm(&films, titre, realisateur);

            break;

        case 2: // Ajouter un acteur à un film
            printf("\nTitre du film    : ");
            scanf("%s", titre);
            printf("\nNom de l'acteur  : ");
            scanf("%s", nom);
            printf("\nPays de l'acteur : ");
            scanf("%s", pays);
            printf("\nFilm non trouvée.\n");
            ajouterActeur();
            break;

        case 3: // Afficher tous les films
            printf("\nListe des films avec acteurs: \n");
            afficherFilms(films);
            break;

        case 4: // Supprimer un film
            printf("\nTitre du film à supprimer : ");
            //...
            break;

        case 5: // Rechercher un film
            printf("Titre du film à rechercher : ");
            printf("Film trouvée :\n");
            printf("Titre : %s, R�alisateur : %s\n");
            printf("Acteurs :\n");
            printf("\nFilm non trouv�.\n");
            break;

        case 6:
            // Libérer la mémoire (supprimer tous les films avec ses acteurs)
            // Afficher la liste films (just for test)
            printf("\nAu revoir !");
            getchar(); // appuyer sur une touche pour sortir
            break;

        default:
            printf("\nChoix invalide !\n");
        }
    } while (choix != 6);
    return 0;
}
