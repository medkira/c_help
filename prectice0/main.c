#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct Node *deleteNode(Node *head, int target)
{
    if (head == NULL)
        return NULL;

    if (head->data == target)
    {
        Node *newHead = head->next;
        free(head);
        return newHead;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        if (current->next->data == target)
        {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            // printf("find it \n");
            return head;
        }
        current = current->next;
    }

    return head;
}

void printLnikedList(Node *head)
{
    // Node *current = head;
    while (head != NULL)
    {
        printf("%d |", head->data);
        head = head->next;
    }
}

void main()
{
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
    node1->data = 10;
    // printf("node1 => %d\n", (*node1).data); ===  printf("node1 => %d\n", node1->data);
    node1->next = node2;
    node2->data = 20;
    node2->next = node3;
    node3->data = 30;
    node3->next = NULL;
    printLnikedList(node1);
    deleteNode(node1, 10);
    printf("\n");
    printLnikedList(node1);
    printLnikedList(node1);
    printf("\n");
}