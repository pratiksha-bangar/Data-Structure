// Queue in java

import java.util.Scanner;

class node
{
    public int data;
    public node next;

    public node(int no)
    {
        data = no;
        next =null;
    }
}

class QueueDemo
{
    public node head;

    public QueueDemo()
    {
        head = null;
    }

    public void enqueue(int no) // insertlast
    {
        node newn = new node(no);

        if(head == null)
        {
            head = newn;
        }
        else
        {
            node temp=head;

            while(temp.next != null)
            {
                temp= temp.next;
            }
            temp.next = newn;
        }
    }

    public void Dequeue() // deletefirst
    {
        if(head == null)
        {
            return ;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else
        {
            head = head.next;
            System.gc();
        }
    }

    public void Display()
    {
        node temp =head;

        while(temp.next != null)
        {
            System.out.println("|"+temp.data);
            temp = temp.next;
        }
    }
}

class Queue
{
    public static void main(String a[])
    {
        Scanner sc = new Scanner(System.in);

        QueueDemo qd = new QueueDemo();

        System.out.print("Insert Element in Queue:");
        qd.enqueue(50);
        qd.enqueue(40);
        qd.enqueue(30);
        qd.enqueue(20);
        qd.enqueue(10);
        qd.Display();
        System.out.println("\n----------------------------------------");

        System.out.print("\n\nDelete Element From Queue:");
        qd.Dequeue();
        qd.Display();
        System.out.println("\n----------------------------------------");
    }
}