package insert;
import java.util.Scanner;
class Queue
{
    final int N=5;
    int queue[]=new int[N];
    int front=-1;
    int rear=-1;
    Scanner keyboard=new Scanner(System.in);
    void enqueue(int x)
    {
        if(rear==N-1)
        {
            System.out.println("Overflow");
        }
        else
        {
            if(front==-1) front=0;
            rear++;
            queue[rear]=x;
            System.out.println(x);   
        }
    }
    //dequeue
    void dequeue()
    {
        if(front==-1 && rear==-1)
        {
            System.out.println("Underflow");
        }
        else if(front==rear)
        {
           front=rear=-1; 
        }
        else
        {
            System.out.println(queue[front]);
            front++;
        }
    }
    //display function
    void display()
    {
        if(front==-1 && rear==-1)
        {
            System.out.println("Empty Queue");
        }
         else
        {
            for(int i=front;i<rear+1;i++)
            {
                System.out.println(queue[i]);
            }
        }
    }
    //isFull function
    boolean isFull()
    {
        return rear==N-1;
    }
    //isEmpty
    boolean isEmpty()
    {
        return (rear==-1 && front==-1);
    }
}
public class Insert
{
    public static void main(String[] args) 
    {
        Scanner keyboard=new Scanner(System.in);
        Queue q=new Queue();
        int function;
        int value;
        while(true)
        {
            System.out.println("1.Enqueue");
            System.out.println("2.Dequeue");
            System.out.println("3.Display");
            System.out.println("4.IsFull");
            System.out.println("5.IsEmpty");
            System.out.println("6.Exit");
            System.out.print("Enter function:");
            function=keyboard.nextInt();
            switch (function) 
          {
                case 1:
                    System.out.println("Enter value:");
                    value=keyboard.nextInt();
                    q.enqueue(value); break;
                case 2: 
                    q.dequeue(); break;
                case 3:  
                    q.display(); break;
                case 4: 
                    System.out.println("IsFull? " + q.isFull()); break;
                case 5: 
                    System.out.println("IsEmpty? " + q.isEmpty()); break;
                case 6:
                    System.out.println("Exit"); return;
                default: System.out.println("Invalid funtion");
           }
        }
    }
    
}



