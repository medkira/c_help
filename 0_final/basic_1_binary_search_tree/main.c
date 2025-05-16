#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int val)
{
    Node *pNewNode = malloc(sizeof *pNewNode);
    pNewNode->value = val;
    pNewNode->left = NULL;
    pNewNode->right = NULL;
    return pNewNode;
}

Node *insert_node(Node *root, int val)
{
    if (root == NULL)
    {
        return create_node(val);
    }

    if (val < root->value)
    {
        root->left = insert_node(root->left, val);
    }
    else if (val > root->value)
    {
        root->right = insert_node(root->right, val);
    }
    return root;
}