#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Head;

void insertNode(Head **head, int data)
{
    Head *temp = (Head *)malloc(sizeof(Head));
    Head *t;
    temp->next = NULL;
    temp->data = data;

    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        t = *head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
}

Head *reverselist(Head *head)
{
    Head *curr = head, *prev = NULL, *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printlist(Head *head)
{
    Head *temp = head;

    if (head == NULL)
    {
        printf(" List is empty \n");
    }
    else
    {
        while (temp != NULL)
        {
            printf(" -> %d ", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    Head *start = NULL;
    printlist(start);
    insertNode(&start, 10);
    insertNode(&start, 11);
    insertNode(&start, 12);
    insertNode(&start, 13);
    printf(" Before reverse linkedlist \n");
    printlist(start);
    start = reverselist(start);
    printf("\nAfter reverse linked list \n");
    printlist(start);
    return 0;
}