import java.util.Scanner;
import java.io.IOException;
class Queue {
    private static final int MAX = 5; // Maximum Queue Size
    private int front, rear;
    private int arr[] = new int[MAX];

    public Queue() {
        front = rear = -1;
    }

    public void enQueue(int val) {
        if (isFull()) {
            System.out.println("\nQueue is Full");
        } else {
            if (front == -1)
                front = 0;
            arr[++rear] = val;
            System.out.println("\nValue Inserted");
        }
    }

    public int deQueue() {
        int element;
        if (isEmpty()) {
            System.out.println("\nQueue is Empty");
            return -1;
        } else {
            element = arr[front];
            if (front == rear)
                front = rear = -1;
            else
                front++;
            System.out.println("\nValue Deleted");
        }
        return element;
    }

    public boolean isEmpty() {
        return (front == -1);
    }

    public boolean isFull() {
        return (rear == MAX - 1);
    }

    public void printQueue() {
        if (isEmpty()) {
            System.out.println("\nQueue is Empty");
            return;
        }
        System.out.println("Queue:");
        for (int i = front; i <= rear; i++)
            System.out.print(arr[i] + "  ");
    }
}

public class Queue_DS {

    static Scanner input = new Scanner(System.in);
    static byte menu() {
        clearConsole();
        System.out.println("1] Insert Element");
        System.out.println("2] Delete Element");
        System.out.println("3] Is Queue Empty ?");
        System.out.println("4] Is Queue Full ?");
        System.out.println("5] Print Queue");
        System.out.println("6] Exit");
        byte choice = 0;
        try {
            System.out.print("\nEnter Your Choice: ");
            choice = input.nextByte();
        } catch (Exception ex) {
            System.out.println("\n\nInvalid Choice");
            input.nextLine();
        }
        return choice;
    }

    // To clear the Console
    static void clearConsole() {
        System.out.println("\033[H\033[2J");
        System.out.flush();
        // System.out.println('\f'); Or // System.out.println('\u000C');
    }

    // To Get Key Press
    static void getKeyPress() {
        try {
            char ch = (char) System.in.read();
        } catch (IOException e) {}
    }

    public static void main(String[] args) {
        Queue q1 = new Queue();

        while (true) {
            switch (menu()) {
                case 1:
                    System.out.print("\nEnter Value to Insert: ");
                    int val = input.nextInt();
                    q1.enQueue(val);
                    break;
                case 2:
                    int value = q1.deQueue(); 
                    if(value >=0)
                       System.out.println("\nDeleted Value: " + value);    
                    break;
                case 3:
                    System.out.println("\nQueue is " + (q1.isEmpty() ? "Empty." : "Not Empty."));
                    break;
                case 4:
                    System.out.println("\nQueue is " + (q1.isFull() ? "Full." : "Not Full."));
                    break;    
                case 5:
                    q1.printQueue();
                    break;
                case 6:
                    System.exit(1);
                    break;
                default:
                    System.out.println("\nInvalid Choice");
                    break;
            }
            getKeyPress();
        }
    }
}
