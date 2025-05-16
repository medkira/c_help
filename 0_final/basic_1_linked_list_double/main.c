#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode *create_node(int val)
{
    DNode *pNode = malloc(sizeof *pNode);

    pNode->data = val;
    pNode->prev = NULL;
    pNode->next = NULL;
    return pNode;
}

void push(DNode **pHead, int val)
{
    DNode *pNewNode = create_node(val);
    pNewNode->next = *pHead;
    pNewNode->prev = NULL;
    (*pHead)->prev = pNewNode;
    *pHead = pNewNode;
}
void print_list(DNode *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (head != NULL)
    {

        // Print previous node's data or "NULL"
        if (head->prev != NULL)
        {
            printf("prev %d | ", head->prev->data);
        }
        else
        {
            printf("prev NULL | ");
        }

        // Print current node's data
        printf("%d", head->data);

        // Print next node's data or "NULL"
        if (head->next != NULL)
        {
            printf(" | next %d\n", head->next->data);
        }
        else
        {
            printf(" | next NULL\n");
        }

        head = head->next; // Move to the next node
    }
}
void delete_list(DNode **pHead)
{
    DNode *current = *pHead;
    while (current != NULL)
    {
        DNode *temp = current;
        current = current->next;
        free(temp);
    }

    free(*pHead);
}

void delete_node_per_value(DNode **pHead, int val)
{
    printf("delete node %d\n", val);
    DNode *current = *pHead;

    while (current != NULL)
    {
        if (current->data == val)
        {
            // start case
            if (current->prev == NULL)
            {
                if (current->next == NULL)
                {
                    free(current);
                    *pHead = NULL;
                    return;
                }
                *pHead = current->next;
                current->next->prev = NULL;
                free(current);
                return;
            }

            // end case
            if (current->next == NULL)
            {
                current->prev->next = NULL;
                free(current);
                return;
            }

            // inner case
            printf("inner case\n");
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return;
        }
        current = current->next;
    }
}

void delete_node_per_value_cleaner(DNode **pHead, int val)
{
    DNode *current = *pHead;

    // Traverse the list to find the node
    while (current != NULL && current->data != val)
    {
        current = current->next;
    }

    // If node wasn't found (or list is empty)
    if (current == NULL)
    {
        printf("Node with value %d not found.\n", val);
        return;
    }

    // --- Node found, now adjust links ---
    printf("Deleting node with value %d\n", val);

    //? 1. Adjust the 'next' pointer of the PREVIOUS node (or the head pointer)
    if (current->prev != NULL)
    {
        // It's not the head node, so update the previous node's 'next'
        current->prev->next = current->next;
    }
    else
    {
        // It IS the head node, so update the main head pointer
        *pHead = current->next;
    }

    //? 2. Adjust the 'prev' pointer of the NEXT node
    if (current->next != NULL)
    {
        // It's not the tail node, so update the next node's 'prev'
        current->next->prev = current->prev;
    }
    // else: It IS the tail node, no next node's 'prev' to update.

    // 3. Free the found node
    free(current);

    // Note: No 'return' is needed here if we only loop until found.
    // If we wanted to delete ALL occurrences, we'd need a slightly
    // different loop structure and handle advancing 'current' carefully after deletion.
}

void delete_node_value(DNode **pHead, int val)
{
    DNode *current = *pHead;
    // fined the current value
    while (current != NULL && current->data != val)
    {
        current = current->next;
    }

    // update the cureent Prev next
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        *pHead = current->next;
    }

    // update the current Next prev
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    // free the current
    free(current);
}

void main()
{
    DNode *head;

    head = create_node(1);
    // push(&head, 2);
    // push(&head, 5);
    // push(&head, 7);
    // push(&head, 9);

    print_list(head);
    delete_node_value(&head, 1);
    print_list(head);

    // int a = 5;
    // int *p = &a;
    // printf("address of %p\n", &a);
    // printf("%p\n", p);
    // printf("%d\n", *p);
    // printf("%p\n", &p);
}