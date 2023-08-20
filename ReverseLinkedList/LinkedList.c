#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

static void reverse(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

void printList(struct Node **head_ref)
{
    struct Node *current = *head_ref;
    while (current != NULL)
    {
        printf("%i \n", current->data);
        current = current->next;
    }
}

void pushBack(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main(int argc, char const *argv[])
{

    struct Node head;
    pushBack(&head, 10);
    pushBack(&head, 20);
    pushBack(&head, 30);
    pushBack(&head, 40);

    printList(&head);

    reverse(&head);

    printList(&head);
    return 0;
}
