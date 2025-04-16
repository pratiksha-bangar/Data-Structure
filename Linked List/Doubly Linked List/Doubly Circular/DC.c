// Doubly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int InsertFirst(PPNODE head,PPNODE tail,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next =NULL;
    newn->previous =NULL;

    if((*head)== NULL && (*tail) ==NULL)
    {
        *head = newn;
        *tail=newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
    (*tail)->next =*head;
    (*head)->previous = *tail;
}

int InsertLast(PPNODE head,PPNODE tail,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next =NULL;
    newn->previous =NULL;

    if((*head)== NULL && (*tail) ==NULL)
    {
        *head = newn;
        *tail=newn;
    }
    else
    {
        (*tail)->next = newn;
        *tail = newn;
    }
    (*tail)->next =*head;
    (*head)->previous = *tail;
}

int DeleteFirst(PPNODE head,PPNODE tail)
{
    if((*head)== NULL && (*tail) ==NULL)
    {
       return 0;
    }
    else if(*head == *tail)
    {
        free(*head);
    }
    else
    {
        PNODE temp=*head;

        *head = (*head)->next;
        free(temp);
        (*tail)->next =*head;
        (*head)->previous = *tail;
    } 
}

int DeleteLast(PPNODE head,PPNODE tail)
{
    if((*head)== NULL && (*tail) ==NULL)
    {
       return 0;
    }
    else if(*head == *tail)
    {
        free(*head);
    }
    else
    {
        PNODE temp=*head;

        while(temp->next != (*tail))
        {
            temp=temp->next;
        }
        free(temp->next);
        *tail = temp;
        (*tail)->next =*head;
        (*head)->previous = *tail;
    } 
}

int InsertAtPosition(PPNODE head,PPNODE tail,int no,int ipos)
{
    if(ipos >=1 || ipos < iCountNode+1)
    {
        return 0;
    }

    if(ipos ==1)
    {
       InsertFirst(head,tail,no);
    }
    else if(ipos == iCountNode+1)
    {
        InsertLast(head,tail,no);
    }
    else
    {
        PNODE temp=*head;

        for(int i=-;i<ipos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->previous= newn;
        temp->next = newn;
        newn->previous = temp;
    } 
}

int DeleteAtPosition(PPNODE head,PPNODE tail,int ipos)
{
    if(ipos >=1 || ipos < iCountNode)
    {
        return 0;
    }

    if(ipos ==1)
    {
       DeleteFirst(head,tail);
    }
    else if(ipos == iCountNode)
    {
        DeleteLast(head,tail);
    }
    else
    {
        PNODE temp=*head;
        PNODE target = NULL;

        for(int i=-;i<ipos-1;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
        temp->next->previos =temp;
    } 
}

int Display(PNODE head,PNODE tail)
{
    PNODE temp=head;
    do
    {
        printf("|%d|<=>",temp->data);
        temp=temp->next;
    }while(temp != tail->next);
}

int main()
{
    PNODE first = NULL;
    PNODE last = NULL;
    int ipos=0,idel=0;

    InsertFirst(&first,&last,30);
    InsertFirst(&first,&last,20);
    InsertFirst(&first,&last,10);
    printf("Insert Elements at First:");
    Display(first,last);

    printf("\n\n---------------------------------------------------");
    InsertLast(&first,&last,90);
    printf("\n\nInsert Elements at Last:");
    Display(first,last);

    printf("\n\n---------------------------------------------------");
    DeleteFirst(&first,&last);
    printf("\n\nDelete First Elements:");
    Display(first,last);

    printf("\n\n---------------------------------------------------");
    DeleteLast(&first,&last);
    printf("\n\nDelete Last Elements:");
    Display(first,last);

    printf("\n\n---------------------------------------------------");
    InsertAtPosition(&first,&last,ipos,800);
    printf("\n\nInsert Elemets at Position:");
    printf("\nEnter Position:");
    scanf("%d",&ipos);
    Display(first,last);

    printf("\n\n---------------------------------------------------");
    DeleteAtPosition(&first,&last,ipos);
    printf("\n\nDelete Elemets at Position:");
    printf("\nEnter Position:");
    scanf("%d",&idel);
    Display(first,last);

    return 0;
}