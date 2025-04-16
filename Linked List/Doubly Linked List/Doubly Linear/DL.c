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

int InsertFirst(PPNODE head,int no)
{
    PNODE newn=NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    newn->previous=NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
        (*head)->previous=newn;
    }
}

int InsertLast(PPNODE head,int no)
{
    PNODE newn=NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    newn->previous=NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        PNODE temp=*head;

        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next =newn;
        newn->previous=temp;
    }
}

int DeleteFirst(PPNODE head)
{
    if(*head == NULL)
    {
        return 0;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        PNODE temp=*head;

        *head = (*head)->next;
        free(temp);
        (*head)->previous=NULL;
    }
}

int DeleteLast(PPNODE head)
{
    if(*head == NULL)
    {
        return 0;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        PNODE temp=*head;

        while(temp->next->next != NULL)
        {
            temp= temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

int InsertAtPosition(PPNODE head , int no, int ipos)
{
    int iCountNode = 0;

    iCountNode = Count(*head);

    if(ipos >= 1 || ipos < iCountNode+1)
    {
        return 0;
    }

    if(ipos == 1)
    {
        InsertFirst(head,no);
    }
    else if (ipos == iCountNode+1)
    {
        InsertLast(head,no);
    }
    else
    {
        PNODE newn=NULL;
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next= NULL;
        newn->previous=NULL;

        PNODE temp=*head;

        for(int i=0;i<ipos-1; i++)
        {
            temp=temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        temp->next->previous=newn;
        newn->previous=temp;
    }
}

int DeleteAtPosition(PPNODE head, int ipos)
{
    int iCountNode = 0;

    iCountNode = Count(*head);

    if(ipos >= 1 || ipos < iCountNode)
    {
        return 0;
    }

    if(ipos == 1)
    {
        DeleteFirst(head);
    }
    else if (ipos == iCountNode)
    {
        DeleteLast(head);
    }
    else
    {
        PNODE temp=*head;
        PNODE target = NULL;

        for(int i=0;i<ipos-1; i++)
        {
            temp=temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
        temp->next->previous =temp;        
    }
}

int Display(PNODE head)
{
    PNODE temp=head;

    while(temp != NULL)
    {
        printf("|%d|->",temp->data);
        temp= temp->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    PNODE temp=head;
    int iCount=0;

    while(temp != NULL)
    {
        iCount++;
        temp= temp->next;
    }
    return iCount;
}

int main()
{
    PNODE first =NULL;
    int ipos=0,idel=0;
    int iRet=0;

    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);
    printf("Insert Element at First:");
    Display(first);
    iRet = Count(first);
    printf("Number of elements are:%d",iRet);

    printf("\n---------------------------------------------------");
    InsertLast(&first,90);
    InsertLast(&first,100);
    printf("\nInsert Element at Last:");
    Display(first);

    printf("\n---------------------------------------------------");
    DeleteFirst(&first);
    printf("\nDelete First Element:");
    Display(first);

    printf("\n---------------------------------------------------");
    DeleteLast(&first);
    printf("\nDelete Last Element:");
    Display(first);

    printf("\n---------------------------------------------------");
    printf("Enter Position:");
    scanf("%d",&ipos);
    InsertAtPosition(&first,400,ipos);
    printf("\nInsert Element at Position:");
    Display(first);

    printf("\n---------------------------------------------------");
    printf("Enter Position:");
    scanf("%d",&del);
    DeleteAtPosition(&first,del);
    printf("\nDelete Element at Position:");
    Display(first);

    return 0;
}