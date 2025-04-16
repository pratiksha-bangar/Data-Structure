// Stack in java

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

class StackDemo
{
    public node head;

    public StackDemo()
    {
        head =null;
    }

    public void push(int no)
    {
        node newn = new node(no);

        if(head == null)
        {
            head = newn;
        }
        else
        {
            newn.next =head;
            head =newn;
        }
    }

    public void pop()
    {
        if(head == null)
        {
            return ;
        }
        else if( head.next == null)
        {
            head =null;
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
        node temp = head;

        while(temp.next != null)
        {
            System.out.println("\n"+temp.data);
            temp =temp.next;
        }
    }
}

class stack 
{
    public static void main(String a[])
    {
        Scanner sc = new Scanner(System.in);

        StackDemo sd = new StackDemo();
    
        System.out.println("Insert Element into Stack:");
        sd.push(50);
        sd.push(40);
        sd.push(30);
        sd.push(20);
        sd.push(10);
        sd.Display();
        System.out.println("----------------------------------------");

        System.out.println("\nDelete Element into Stack:");
        sd.pop();
        sd.pop();
        sd.Display();
        System.out.println("----------------------------------------");

    }
}