#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create_stack()
{
    return NULL;
}

Node *create_node(int val)
{
    Node *pNode = malloc(sizeof *pNode);
    pNode->data = val;
    pNode->next = NULL;
    return pNode;
}

void push(Node **pHead, int val)
{
    Node *pNewNode = create_node(val);
    pNewNode->next = *pHead;
    *pHead = pNewNode;
}

void pop(Node **pHead)
{
    if (*pHead == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    Node *popNode = *pHead;
    *pHead = popNode->next;
    free(popNode);
}

void print_list(Node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
    }

    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void main()
{
    Node *stack = create_stack();
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    print_list(stack);
    pop(&stack);
    print_list(stack);
}