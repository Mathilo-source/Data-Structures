import java.util.Scanner;

class Queue {

    final int size = 5;
    int[] CQ = new int[size];
    int front = 0;
    int rear = 0;
    int count = 0;
    Scanner input = new Scanner(System.in);

    void enqueue() {
        int data;
        if (count == size) {
            System.out.println("Full");
        } else {
            System.out.println("Enter your data");
            data = input.nextInt();
            CQ[rear] = data;
            rear = (rear + 1) % size;
            count++;
        }
    }

    void dequeue() {
        if (count == 0) {
            System.out.println("Empty");
        } else {
            front = (front + 1) % size;
            count--;
        }
    }
}

public class CircularQueue {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Queue q = new Queue();
        int function;
        while (true) {
            System.out.println("1.Enqueue");
            System.out.println("2.Dequeue");
            System.out.println("6.Exit");
            System.out.print("Enter function:");
            function = input.nextInt();
            switch (function) {
                case 1:
                    q.enqueue();
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 6:
                    System.out.println("Exit");
                default:
                    System.out.println("Invalid funtion");
                    return;
            }
        }
    }
}