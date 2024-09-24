#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data ; 
    struct node *next;
}Head;

void insertNode(Head **head,int data){ // insert node 
Head *temp = (Head *)malloc(sizeof(Head)); 
Head *t; 
temp->next = NULL;
temp->data = data;

if ( *head == NULL){
    *head = temp ; 
}
else{
    t = *head ;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
      
}

}


void printlist(Head *head) // print list 
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
int main(){
    Head *start=NULL;
    insertNode(&start,10);
    insertNode(&start,11);
    insertNode(&start,12);
    insertNode(&start,13);
    printlist(start);
    return 0 ;
}