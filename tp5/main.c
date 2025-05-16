#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// création d'un nouveau noeud
Node *createNode(int value)
{
    Node *n = malloc(sizeof(Node));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

// insertion d'un nouveau noeud dans l'ABR référencé par proot
// NB: tous les noeuds sont distincts !
// proot est l'adresse du pointeur de la racine d'un ABR (passage par référence)
/* Principe :
Pour chaque noeud n, toutes les valeurs du sous-arbre gauche sont inférieures à celle du noeud n,
et toutes celles du sous-arbre droit sont supérieures ou égales (selon l’implémentation) à celle du n*/
void insertNode(Node **proot, int value)
{
    if (*(proot) == NULL)
    {
        *proot = createNode(value);
    }
    else
    {
        if (value < (*proot)->data)
        {
            insertNode(&(*proot)->left, value);
        }
        else if (value > (*proot)->data)
        {
            insertNode(&(*proot)->right, value);
        }
    }
}

// remplissage d'un ABR à partir d'un tableau de taille n
void fillTree(Node **proot, int t[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        insertNode(proot, t[i]);
}

// affichage d'un ABR selon le parcours preOrder (preFixé: RGD)
// exemple: [50] [20] [10] [40] [30] [60] [90] [80] [70]
// Ce parcours est utile pour exporter ou sauvegarder la structure
// d'un ABR pour pouvoir le reconstruire
void preOrder(Node *root)
{

    if (root != NULL)
    {
        printf("[%d]", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// affichage d'un ABR selon le parcours inOrder (inFixé: GRD)
// Ce parcours renvoie les éléments dans l’ordre croissant
// exemple: [10] [20] [30] [40] [50] [60] [70] [80] [90]
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("[%d]", root->data);
        inOrder(root->right);
    }
}

// affichage d'un ABR selon le parcours postOrder (postFixé: GDR)
// exemple: [10] [30] [40] [20] [70] [80] [90] [60] [50]
// Ce parcours est utile pour supprimer tous les noeuds (libération mémoire)
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d]", root->data);
    }
}

// recherche d'un noeud dans un ABR
// renvoie NULL, si l'ABR est vide ou le noeud n'existe pas
Node *searchNode(Node *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value == root->data)
        return root;

    if (value < root->data)
        return searchNode(root->left, value);
    else
        return searchNode(root->right, value);
}

// hauteur d'un ABR: longueur du plus long chemin de la racine jusqu’à une feuille.
// retourne -1 si l'ABR est vide
int treeHeight(Node *root)
{
}

// profondeur d’un noeud (distance par rapport à la racine en nombre de noeuds)
// retourne -1 si l'ABR est vide
int nodeDepth(Node *root, int value)
{
}

// retourne le pointeur du noeud contenant le plus petit élément dans l'ABR root
Node *findMin(Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// retourne le pointeur du noeud contenant le plus grand élément dans l'ABR root
Node *findMax(Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// renvoie le nombre de feuilles d'un ABR pointé par root
int countLeaves(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

// vidage d'un ABR (libérer la mémoire allouée par tous les noeuds)
void freeTree(Node *root)
{
}

// suppression du noeud contenant la valeur value.
// proot est l'adresse du pointeur de la racine d'un ABR
// retorune NULL si l'ABR est vide !
// gérer les trois cas classiques de suppression :
// 1. noeud sans enfant
// 2. noeud avec un seul enfant
// 3. noeud avec deux enfants
void deleteNode(Node **proot, int value)
{
}

// programme principal
int main()
{
    Node *myTree = NULL;
    int choice, val;

    do
    {
        printf("\n--- MENU ABR --------------------------\n");
        printf("01. Insertion d'un nouveau noeud\n");
        printf("02. Remplissage a partir d'un tableau\n");
        printf("03. Parcours infixe (inOrder)\n");
        printf("04. Parcours prefixe (preOrder)\n");
        printf("05. Parcours postfixe (postOrder)\n");
        printf("06. Rechercher d'un noeud\n");
        printf("07. Supprimer un noeud\n");
        printf("08. Hauteur de l'ABR\n");
        printf("09. Profondeur d'un noeud\n");
        printf("10. Valeur minimale de l'ABR\n");
        printf("11. Valeur maximale de l'ABR\n");
        printf("12. Nombre de feuilles\n");
        printf("13. Vidage de l'ABR\n");
        printf("00. Quitter\n");
        printf("----------------------------------------\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Valeur à insérer : ");
            scanf("%d", &val);
            insertNode(&myTree, val);
            break;
        case 2:
        {
            int n = 9;
            int t[] = {50, 20, 60, 90, 80, 10, 40, 70, 30};
            fillTree(&myTree, t, n);
            printf("\n");
        }
        break;
        case 3:
            printf("\nParcours infixe (inOrder)\n");
            inOrder(myTree);
            printf("\n");
            break;
        case 4:
            printf("\nParcours prefixe (preOrder)\n");
            preOrder(myTree);
            printf("\n");
            break;
        case 5:
            printf("\nParcours postfixe (postOrder)\n");
            postOrder(myTree);
            printf("\n");
            break;
        case 6:
            printf("Valeur à rechercher : ");
            scanf("%d", &val);
            if (searchNode(myTree, val) != NULL)
                printf("Valeur trouvee.\n");
            else
                printf("Valeur non trouvee.\n");
            break;
        case 7:
            printf("Valeur à supprimer : ");
            scanf("%d", &val);
            break;
        case 8:
            printf("Hauteur de l'arbre : %d\n");
            break;
        case 9:
            printf("Valeur à évaluer : ");
            scanf("%d", &val);
            printf("Profondeur : %d\n");
            break;
        case 10:
            printf("Min : %d\n", findMin(myTree)->data);
            break;
        case 11:
            printf("Max : %d\n", findMax(myTree)->data);
            break;
        case 12:
            printf("Nombre de feuilles : %d\n", countLeaves(myTree));

            break;
        case 13:
            printf("Arbre vide.\n");
            break;
        case 0:
            printf("Fin...\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choice != 0);
}