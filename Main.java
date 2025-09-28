package main;

import java.util.Scanner;
class Stack
{
 final int N=5;
 int stack[]=new int[N];
 int top=-1;
 Scanner keyboard=new Scanner(System.in);
 //push function
 void push()
 {
     if(top==N-1)
     {
         System.out.println("Overflow");
     }
     else
     {
         int item;
         System.out.println("Enter your value");
         item=keyboard.nextInt();
         top++;
         stack[top]=item;
     }
 }
 //pop function
 void pop()
 {
     int item;
     if(top==-1)
     {
         System.out.println("Underflow");
     }
     else
     {
         item=stack[top];
         top--;
         System.out.println(item);
     }
 }
 //top function
 void top()
 {
     if(top==-1)
     {
         System.out.println("Empty stack");
     }
     else
     {
         System.out.println(stack[top]);
     }
 }
 //display function
 void display()
 {
     if(top==-1)
     {
         System.out.println("Stack is empty");
     }
     else
     {
         for(int i=top;i>=0;i--)
         {
             System.out.println(stack[i]);
         }
     }
 }
 //size function
 int size()
 {
     return top+1;
 }
 //isEmpty function
 boolean isEmpty()
 {
     return(top==-1);
 }
 //isFull
 boolean isFull()
 {
     return(top==N-1);
 }
}
public class Main 
{
    public static void main(String[] args) 
    {
      Scanner keyboard=new Scanner(System.in);
      Stack s=new Stack();
      int function;
      while(true)
      {
          
          System.out.println("1.Push");
          System.out.println("2.Pop");
          System.out.println("3.Top");
          System.out.println("4.Display");
          System.out.println("5.size");
          System.out.println("6.isEmpty");
          System.out.println("7.isFull");
          System.out.println("8.Exit");
          System.out.print("Enter function: ");
          function=keyboard.nextInt();
          switch (function) 
          {
                case 1: s.push(); break;
                case 2: s.pop(); break;
                case 3: s.top(); break;
                case 4: s.display(); break;
                case 5: System.out.println("Current size: " + s.size()); break;
                case 6: System.out.println("IsEmpty? " + s.isEmpty()); break;
                case 7: System.out.println("IsFull? " + s.isFull()); break;
                case 8: System.out.println("Exit"); return;
                default: System.out.println("Invalid funtion");
      }
    }
    
}
