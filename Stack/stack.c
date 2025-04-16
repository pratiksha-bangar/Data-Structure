// Stack

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

void push(PPNODE head,int no)   // insertfirst
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next =NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
}

void pop(PPNODE head)    // deletefirst
{
    PNODE temp = NULL;
    if(*head == NULL)
    {
        return ;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        PNODE temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void Display(PNODE head)
{
    PNODE temp = head;

    while(temp->next != NULL)
    {
        printf("\n|%d|",temp->data);
        temp= temp->next;
    }
}

int main()
{
    PNODE first=NULL;

    printf("Push Elements in Stack:");
    push(&first,50);
    push(&first,40);
    push(&first,30);
    push(&first,20);
    push(&first,10);
    Display(first);
    printf("\n-------------------------------------");

    printf("\nPop Element from stack:");
    pop(&first);
    Display(first);
    printf("\n-------------------------------------");
}