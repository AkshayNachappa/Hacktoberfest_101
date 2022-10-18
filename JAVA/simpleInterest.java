import java.util.Scanner;

// Program for find simple Interest

public class simpleInterest {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Amount : ");
        float amount = input.nextInt();

        System.out.println("Enter Rate : ");
        float rate = input.nextInt();

        System.out.println("Enter Time : ");
        float time = input.nextInt();

        float interest;
        interest = (amount * rate * time) / 100;
        System.out.println("Simple Interest is: " + interest);
    }
}