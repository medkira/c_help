#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tache
{
    int id;
    int duree;    // Durée en Millisecondes
    int priorite; // 1, 2 ou 3
    struct Tache *suivant;
} Tache;

typedef struct FileTaches
{
    Tache *tete;
    Tache *queue;
} FileTaches;

// Initialiser la file
void initFile(FileTaches *file)
{
    file->tete = NULL;
    file->queue = NULL;
}

// Vérifier si la file est vide
bool estVide(FileTaches *file)
{
    return (file->tete == NULL);
}

// Ajouter une tâche par ordre de priorité (Enfiler)
// Crée une nouvelle tâche et l'ajoute par ordre de priorité
// la tâche à basse priorité doit être ajoutée en queue de file
// Les tâches de même priorité doivent être ajoutées dans leur ordre d'arrivée
Tache *createTask(int id, int duree, int priorite)
{
    Tache *n = (Tache *)malloc(sizeof(Tache));
    n->id = id;
    n->duree = duree;
    n->priorite = priorite;
    n->suivant = NULL;

    return n;
}

void enfilerTache(FileTaches *file, int id, int duree, int priorite)
{
    Tache *n = createTask(id, duree, priorite);

    //? cas1: file vide
    if (estVide(file))
        file->tete = file->queue = n;
    else
    {
        //? cas2: insertion au debut
        if (priorite < file->tete->priorite)
        {
            n->suivant = file->tete;
            file->tete = n;
        }
        else
        {
            //? cas3: instertion a la fin
            if (priorite >= file->tete->priorite)
            {
                file->queue->suivant = n;
                file->queue = n;
            }
            else //? cas4 insertion au milieu
            {
                // trouver la position d'insertion
                Tache *c = file->tete;
                Tache *p;
                while (c->priorite <= priorite)
                {
                    p = c;
                    c = c->suivant;
                }
                p->suivant = n;
                n->suivant = c;
            }
        }
    }
    // ce message est un simple test
    printf("Tâche %d (durée: %dms, priorité: %d) ajoutée.\n", id, duree, priorite);
}

// Exécuter et défiler les tâches (FIFO)
// Utiliser la fonction sleep(n)/Sleep(n) pour simuler le temps d'exécution
// Bibliothèque : <unistd.h> (pour sleep) et <windows.h> (pour Sleep)
void defilerTaches(FileTaches *file)
{
    printf("Aucune tâche en attente.\n");
    printf("Exécution de la tâche %d (durée: %dms)...\n");
    printf("Tâche %d terminée.\n");
}

// Afficher les tâches en attente
void afficherFile(FileTaches *file)
{
    if (estVide(file))
        printf("La file est vide.\n");
    else
    {
        Tache *courant = file->tete;
        printf("File des tâches : ");
        while (courant != NULL)
        {
            printf("[%d: %dms, %d] -> ", courant->id, courant->duree, courant->priorite);
            courant = courant->suivant;
        }
        printf("NULL\n");
    }
}

// Supprimer une tâche (par ID)
void supprimerTache(FileTaches *file, int id)
{
    //...
    // ceci est un simple message de test
    printf("Tâche %d supprimée.\n", id);
}

// Fonction principale
int main()
{
    FileTaches tasks;

    // initialiser la file
    initFile(&tasks);

    // ajouter de tâches en respectant l'ordre de priorité {id, durée, priorité} :
    //{1, 5000, 1}, {2, 2000, 1}, {3, 7000, 3}, {4, 5000, 2} et {5, 6000, 1};
    enfilerTache(&tasks, 1, 5000, 1);
    enfilerTache(&tasks, 2, 2000, 1);
    enfilerTache(&tasks, 3, 7000, 3);
    enfilerTache(&tasks, 4, 5000, 2);
    enfilerTache(&tasks, 5, 6000, 1);
    // 1 2 5 4 3
    // afficher la file
    afficherFile(&tasks);
    // supprimer la tâche : id = 2

    // réafficher la file

    // exécuter et défiler les tâches

    // réafficher la file
}
