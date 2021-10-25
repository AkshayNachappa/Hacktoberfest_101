import java.util.Scanner;

class GCD {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println(greatestCommonDivisor(scanner.nextInt(), scanner.nextInt()));
    }
    //Euclidean Algorithm
    public static int greatestCommonDivisor(int a, int b) {
        if (b == 0)
            return a;
        else
            return greatestCommonDivisor(b, a % b);
    }
}
