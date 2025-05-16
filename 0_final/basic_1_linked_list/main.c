#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create_node(int val)
{
    Node *n = malloc(sizeof *n); // Node *n = malloc(sizeof(Node));
    if (!n)
        return NULL;
    n->data = val;

    n->next = NULL;
    // printf("%p\n", n);
    return n;
};

// hear we will push a value in the head of list
// so its like we will create new head so we need the adddress of the head
// so we pass a pointer that point to the head of the list => **pHead / its ** bcs the head it self is a poter so its  pointer to a pointer
// now we have acccess to the head address using the derefrence * and by that we can change the value of the head and that bcs of =>  the pointer taht pint to head

// the head address in the ned changed using the pointer taht point to head
void push(Node **pHead, int val)
{
    Node *newNode = create_node(val);
    newNode->next = *pHead;
    *pHead = newNode;
}

void delete_list(Node **pHead)
{
    Node *current = *pHead;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *pHead = NULL; // we need to make the add ress of the pinter taht pit to head null
}

void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        // the head being passed par value and whe nwe change the head it will not affect the original head
        // but that doesnt mean tah twe can't change the original list bcs we passed a valueo of the head
        // so we have a local variable that have head address and we wchange taht local value the original head will not be effected
        // but we have the access the orginal address so we can change the value inside of the node

        // in other words we can change the address of any node expect of the head bcs its passed par value
        // ! there is a diffrence between changing the data inside the node or the nex taddres of teh node
        // ! and the address of the node it self
        // head->data = 0;
        head = head->next;
    }

    // Node *p = head;
    // while (p != NULL)
    // {

    //     printf("%d\n", p->data);
    //     p = p->next;
    // }
}

void main()
{
    Node *head = NULL;
    head = create_node(1);
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);

    // printf("%p\n", head);
    // printf("%d\n", head->data);
    print_list(head);
    delete_list(&head);
    print_list(head);

    free(head);
}