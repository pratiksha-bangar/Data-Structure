// Queue 

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Enqueue(PPNODE head,int no) // inserlast
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data =no;
    newn->next =NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        PNODE temp =*head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Dequeue(PPNODE head)
{
    if(*head == NULL)
    {
        return ;
    }
    else if((*head)->next ==NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        PNODE temp = NULL;
        temp =*head;

        *head = (*head)->next ;
        free(temp);
    }
}

void Display(PNODE head)
{
    PNODE temp = head;

    while(temp->next != NULL)
    {
        printf("%d|",temp->data);
        temp =temp->next;
    }
}

int main()
{
    PNODE first =NULL;

    printf("Insert Element into Queue:\n");
    Enqueue(&first,80);
    Enqueue(&first,70);
    Enqueue(&first,60);
    Enqueue(&first,50);
    Enqueue(&first,40);
    Enqueue(&first,30);
    Enqueue(&first,20);
    Enqueue(&first,10);
    Display(first);
    printf("\n-------------------------------------------");

    printf("\n\nDelete Elements from queue:\n");
    Dequeue(&first);
    Dequeue(&first);
    Display(first);
    printf("\n--------------------------------------------");

    return 0;
}