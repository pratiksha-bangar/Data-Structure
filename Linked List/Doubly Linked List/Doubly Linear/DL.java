// Doubly Liner linked list

import java.util.Scanner;

class node
{
    public int data;
    public node next;
    public node previous;

    public node(int no)
    {
        data = no;
        next =null;
        previous=null;
    }
}

class Doubly 
{
    public node head;

    public Doubly()
    {
        head =null;
    }

    public void InserFirst(int no)
    {
        node newn = new node(no);

        if(head == null)
        {
            head = newn;
        }
        else
        {
            newn.next = head;
            head.next.previous=nenw;
            head =newn;
        }
    }

    public void InsertLast(int no)
    {
        node newn= new node(no);

        if(head == null)
        {
            head = newn;
        }
        else
        {
            node temp=head;

            wile(temp.next != null)
            {
                temp =temp.next;
            }
            temp.next = newn;
            newn.previous= temp;
        }
    }

    public void DeleteFirst()
    {
        if(head == null)
        {
            return 0;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else
        {
            node temp= head;

            head = head.next;
            head.previous =null;

            System.gc():
        }
    }

    public void DeleteLast()
    {
        if(head == null)
        {
            return 0;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else
        {
            node temp=head;

            while(temp.next.next != null)
            {
                temp= temp.next;
            }
            temp.next=null;
            System.gc();
        }
    }
    
    public void Display()
    {
        node temp=head;

        while(temp != null)
        {
            System.out.println("|"+temp.data+"|->");
            temp=temp.next;
        }
        System.out.println("NULL\n");
    }
}

class DL 
{
    public static void main(String a[])
    {
        Scanner sc = new Scnner(System.in);

        Doubly d = new Doubly();

        System.out.println("Insert Element at First:");
        d.InserFirst(30);
        d.InserFirst(20);
        d.InserFirst(10);
        d.Display();
        System.out.println("\n------------------------------------------");

        System.out.println("Insert Element at Last:");
        d.InsertLast(900);
        d.InsertLast(890);
        d.Display();
        System.out.println("\n------------------------------------------");

        System.out.println("Delete First Element:");
        d.DeleteFirst();
        d.Display();
        System.out.println("\n------------------------------------------");
    }
}