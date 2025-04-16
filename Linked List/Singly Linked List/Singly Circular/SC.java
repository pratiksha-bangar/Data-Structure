// Singly Circular Linked List

import java.util.Scanner;

class node
{
    public int data;
    public node next;

    public node(int no)
    {
        data =no;
        next =null;
    }
}

class Scircular
{
    public node head;
    public node tail;

    pblic Scircular()
    {
        head =null;
        tail=null;
    }

    public void InserFirst(int no)
    {
        node newn = new node(no);

        if(head == null && tail == null)
        {
            head = newn;
            tail=newn;
        }
        else
        {
            newn.next = head;
            head = newn;
        }
        tail.next = head;
    }

    public void Display()
    {
        node temp =head;

        while(temp != null)
        {
            System.out.println("|"+temp.data+"|->");
            temp = temp.next;
        }
    }

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(head == null && tail == null)
        {
            head = newn;
            tail =newn;
        }
        else
        {
            tail.next = newn;
            tail=newn;
        }
        tail.next =head;
    }

    public void DeleteFirst()
    {
        if(head == null && tail == null)
        {
            return 0;
        }
        else if( head == tail)
        {
            head = null;
            tail=null;
            System.gc();
        }
        else
        {
            head = head.next;
            System.gc();
            tail.next = head;
        }
    }

    public void DeleteLast()
    {
        if(head == null && tail == null)
        {
            return 0;
        }
        else if(head == tail)
        {
            head = null;
            tail=null;
            System.gc();
        }
        else
        {
            node temp=head;

            while(temp.next.next != tail)
            {
                temp =temp.next;
            }
            temp.next = tail;
            System.gc();
            tail.next =head;
        }
    }
}

class SC 
{
    public static void main(String a[])
    {
        Scanner sc = new Scaner(System.in);

        Scircular sc = new Scircular();

        System.out.println("Insert Element at First:");
        sc.InserFirst(30);
        sc.InserFirst(20);
        sc.InserFirst(10);
        sc.Display();
        System.out.println("\n----------------------------------------------");

        System.out.println("Insert Element at Last:");
        sc.InsertLast(300);
        sc.Display();
        System.out.println("\n----------------------------------------------");


        System.out.println("Delete First Element:");
        sc.DeleteFirst();
        sc.Display();
        System.out.println("\n----------------------------------------------");

        System.out.println("Delete Last Element:");
        sc.DeleteLast();
        sc.Display();
        System.out.println("\n----------------------------------------------");

    }
}