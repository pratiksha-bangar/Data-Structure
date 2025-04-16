// Singly Linear Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int InsertFirst(PPNODE head, int no)
{
    PNODE newn=NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else 
    {
        newn->next = *head;
        *head= newn;
    }
}

int InsertLast(PPNODE head, int no)
{
    PNODE newn=NULL;
    PNODE temp=*head;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else 
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = newn;
    }
}

int DeleteFirst(PPNODE head)
{
    PNODE temp=*head;

    if(*head == NULL)
    {
        return 0;
    }
    else if((*head)->next == NULL)
    {
        free (*head);
        *head=NULL;
    }
    else 
    {
       *head = (*head)->next;
       free (temp);
    }
}

int DeleteLast(PPNODE head)
{
    PNODE temp=*head;

    if(*head == NULL)
    {
        return 0;
    }
    else if((*head)->next == NULL)
    {
        free (*head);
        *head=NULL;
    }
    else 
    {
       while(temp->next->next != NULL)
       {
        temp= temp->next;
       }
       free (temp->next);
       temp->next = NULL;
    }
}

int InsertAtPosition(PPNODE head ,int no,int ipos)
{
    int iCountNode = iCount(*head);

    if(ipos <= 1 || ipos > iCountNode+1 )
    {
        return 0;
    }

    if(ipos == 1)
    {
        InsertFirst(head,no);
    }
    else if(ipos == iCountNode +1)
    {
        InsertLast(head,no);
    }
    else
    {
        PNODE newn=NULL;
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        PNODE temp= *head;

        for(int i=0;i<ipos-1;i++)
        {
            temp =temp->next;
        }
        newn->next = temp->next;
        temp->next=newn;
    }
}

int DeleteAtPosition(PPNODE head ,int ipos)
{
    int iCountNode = iCount(*head);

    if(ipos <= 1 || ipos > iCountNode )
    {
        return 0;
    }

    if(ipos == 1)
    {
        DeleteFirst(head);
    }
    else if(ipos == iCountNode)
    {
        DeleteLast(head);
    }
    else
    {
        PNODE temp= *head;

        for(int i=0;i<ipos-1;i++)
        {
            temp =temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

void Display(PNODE head)
{
    PNODE temp= NULL;
    temp=head;

    while(temp != NULL)
    {
        printf("|%d|->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int iCount(PNODE head)
{
    int iCnt=0;
    PNODE temp=head;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt; 
}


int main()
{
    int iRet=0,ipos=0,del=0;

    PNODE first=NULL;

    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);
    printf("Insert Elements at First\n");
    Display(first);
    iRet= iCount(first);
    printf("\nNumber of Elements:%d",iRet);
    printf("\n---------------------------------------------\n");

    printf("\nInsert Elements at Last\n");
    InsertLast(&first,40);
    InsertLast(&first,50);
    InsertLast(&first,60);
    Display(first);
    printf("\n---------------------------------------------\n");

    printf("\nDelete First Element\n");
    DeleteFirst(&first);
    Display(first);
    printf("\n---------------------------------------------\n");

    printf("\nDelete Last Element\n");
    DeleteLast(&first);
    Display(first);
    printf("\n---------------------------------------------\n");

    printf("\nInsert At position");
    printf("Enter Position:");
    scanf("%d",&ipos);
    InsertAtPosition(&first,ipos,200);
    Display(first);
    printf("\n---------------------------------------------\n");

    printf("\nDelete At position");
    printf("Enter Position:");
    scanf("%d",&del);
    InsertAtPosition(&first,del);
    Display(first);
    printf("\n---------------------------------------------\n");

    return 0;
}

