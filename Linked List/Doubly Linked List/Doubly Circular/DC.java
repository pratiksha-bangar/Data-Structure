// Doubly circular linked list

import java.Util.Scanner;

class node
{
    public int data;
    public node next;
    public node previous;

    public node(int no)
    {
        data=no;
        next=null;
        previous=null;
    }
}

class Dcircular
{
    public node head ;
    public node tail;

    public Dcircular()
    {
        head =null;
        tail=null;
    }

    public void InserFirst(int no)
    {
        node newn= new node(no);

        if(head == null && tail == null)
        {
            head = newn;
            tail= newn;
        }
        else
        {
            newn.next = head;
            head.next.previous=newn;
            head = newn;
        }
        head.previous=tail;
        tail.next =head;
    }

    public void InsertLast(int no)
    {
        node newn=new node(no);

        if(head == null && tail == null)
        {
            head = newn;
            tail= newn;
        }
        else
        {
            tail.next = newn;
            tail.next.previous=tail;
            tail=newn;
        }
        tail.next =head;
        head.prevoius=tail;
    }

    public void DeleteFirst()
    {
        if(head == null && tail == null)
        {
            return 0;
        }
        else if(head == tail)
        {
            head = null;
            tail = null;
            System.gc();
        }
        else
        {
            head = head.next;
            System.gc();
            head.previous=tail;
            tail.next =head;
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
            tail =null;
            System.gc();
        }
        else
        {
            node temp=head;

            while(temp.next.next != tail)
            {
                temp=temp.next;
            }
            temp.next = tail;
            System.gc();
            tail.next =head;
            head.previous=tail;
        }
    }

    public void Display()
    {
        node temp=head;

        while(temp != tail)
        {
            System.out.println("|"+temp.data+"|<=>");
            temp=temp.next;
        }
    }
}

class DC 
{
    public static void main(String a[])
    {
        Scanner sc = new Scanner(System.in);

        Dcircular dc = new Dcircular();

        System.out.println("Insert elements at first:");
        dc. InsertFirst(30);
        dc.InsertFirst(20);
        dc.InsertFirst(10);
        dc.Display();
        System.out.println("\n-----------------------------------------");

        System.out.println("Insert elements at Last:");
        dc.InsertLast(300);
        dc.InsertLast(400);
        dc.Display();
        System.out.println("\n-----------------------------------------");

        System.out.println("Delete Element at First:");
        dc.DeleteFirst();
        dc.Display();
        System.out.println("\n-----------------------------------------");

        System.out.println("Delete Element at Last:");
        dc.DeleteLast();
        dc.Display();
        System.out.println("\n-----------------------------------------");
    }
}