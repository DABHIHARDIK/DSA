#include <stdio.h>
#include <stdlib.h>

typedef struct Head
{
    int data;
    struct Head *next;

} Node;

Node *addtoempty(Node *last, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    last = temp;
    last->next = last;
    return (last);
}

Node *addatend(Node *last, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = last->next;
    temp->data = data;
    last->next = temp;
    last = temp;
    return (last);
}

Node *createlist(Node *last)
{
    int num, value;
    printf("How many number you want to enter\n");
    scanf("%d", &num);
    printf("Enter a first data for the list\n");
    scanf("%d", &value);
    last = addtoempty(last, value);
    for (int i = 2; i <= num; i++)
    {
        printf("enter data for the list\n ");
        scanf("%d", &value);
        last = addatend(last, value);
    }
    return last;
}
void display(Node *last)
{
    Node *temp;
    if (last == NULL)
    {
        printf(" list is empty\n");
    }
    else
    {
        temp = last->next;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != last->next);
    }
}

Node *addatbeg(Node *last, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    return last;
}

Node *addafter(Node *last, int data, int item)
{

    Node *tra;
    tra = last->next;
    do
    {
        if (tra->data == item)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = data;
            temp->next = tra->next;
            tra->next = temp;
            if (tra == last)
                last = temp;
            return (last);
        }
        tra = tra->next;
    } while (tra != last->next);
    printf("%d is not in the list \n", item);
    return last;
}
Node *del(Node *last, int value)
{
    Node *t, *p;
    if (last == NULL)
    {
        printf("list is empty\n");
        return last;
    }
    if (last == last->next && last->data == value)
    {
        t = last;
        last = NULL;
        free(t);
        return last;
    }
    if (last->next->data == value)
    {
        t = last->next;
        last->next = t->next;
        free(t);
        return (last);
    }
    p = last->next;
    while (p->next != last)
    {
        if (p->next->data == value)
        {
            t = p->next;
            p->next = t->next;
            free(t);
            return last;
        }
        p = p->next;
    }
    if (last->data == value)
    {
        t = last;
        p->next = last->next;
        last = p;
        free(t);
        return last;
    }
    printf("%d is not found in list \n", value);
    return (last);
}

int main()
{
    int choice, value;
    int item;
    Node *last = NULL;
    while (1)
    {
        printf("\n 1. Create list \n 2. Display list \n 3. Add to empty list \n 4. Add at beginning \n 5. add at end \n 6. add after \n 7. Delete \n 8. Exit");
        printf("\nenter your choise : - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            last = createlist(last);
            break;

        case 2:
            display(last);
            break;

        case 3:
            printf("Enter a number for the list\n");

            scanf("%d", &value);
            last = addtoempty(last, value);
            break;
        case 4:
            printf("enter a numer for the list\n");
            scanf("%d", &value);
            last = addatbeg(last, value);
            break;
        case 5:
            printf("enter a value  for the list \n");
            scanf("%d", &value);
            last = addatend(last, value);
            break;
        case 6:
            printf("Enter a number for the list \n");
            scanf("%d", &value);
            printf("Enter item value after new value to b e inserted\n");
            scanf("%d", &item);
            last = addafter(last, value, item);
            break;
        case 7:
            printf("Enter value of element to be deleted");
            scanf("%d", &value);
            last = del(last, value);
        case 8:
            exit(1);

        default:
            printf("invalid choise");
            break;
        }
    }

    return 0;
}