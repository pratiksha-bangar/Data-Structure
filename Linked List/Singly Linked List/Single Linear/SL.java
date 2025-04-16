// Singly Linear linked list

import java.util.Scanner;

class node
{
    public int data;
    public node next;

    public node(int no)
    {
        data=no;
        next =null;
    }
}

class Singly 
{
    public node head;

    public Singly()
    {
        head =null;
    }

    public void InserFirst(int no)
    {
        node newn = new node(no);

        if(head == null)
        {
            head =newn;
        }
        else
        {
            nenw.next = head;
            head = newn;
        }
    }

    public void InsertLast(int no);
    {
        node newn= new node(no);

        if(head == null)
        {
            head = newn;
        }
        else
        {
            node temp =head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
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
            node temp =head;

            head = head.next;
            System.gc();
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
                temp=temp.next;
            }
            temp.next = null;
            System.gc();
        }
    }

    public void Display()
    {
        node temp=head;

        while(temp != null)
        {
            System.out.println("|"+temp.data+"|->");
            temp = temp.next;
        }
        System.out.println("NULL\n");
    }
}

class SL 
{
    public static void main(String a[])
    {
        Scanner sc = new Scaner(System.in);

        Singly s = new Singly();

        System.out.println("Insert Elements at First:");
        s.InserFirst(30);
        s.InserFirst(20);
        s.InserFirst(10);
        s.Display();
        System.out.println("\n--------------------------------------");

        System.out.println("Insert Elements at Last:");
        s.InserFirst(90);
        s.InserFirst(110);
        s.Display();
        System.out.println("\n--------------------------------------");

        System.out.println("Delete first Element:");
        s.DeleteFirst();
        s.Display();
        System.out.println("\n--------------------------------------");

        System.out.println("Delete last Elemet:");
        s.DeleteLast();
        s.Display();
        System.out.println("\n--------------------------------------");
    }
}