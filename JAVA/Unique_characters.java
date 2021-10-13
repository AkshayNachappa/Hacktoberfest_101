/*
Prints only unique characters from alphabet-only string
Checks for numeric or special characters
*/

import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string");
        char uCHar[] = new char[26];
        String str= sc.nextLine();
        //System.out.println(str);

        if ((str == null) || (str.equals("")) || (!str.matches("^[ A-Za-z]+$"))) {
            System.out.println("Invalid Sentence");
        } else {
            int[] count = new int[123];

            for (int i = 0; i < str.length(); i++)
                if(str.charAt(i)!=' ')
                    count[(int)str.charAt(i)]++;
            int currCount = 0;
            for (int i = 0; i < str.length(); i++)
                if (count[(int)str.charAt(i)] == 1) {
                    currCount++;
                }
            if(currCount == 0)
                System.out.println("No unique Characters");
            else{
                System.out.println("Unique characters: ");
                for (int i = 0; i < str.length(); i++)
                    if (count[(int)str.charAt(i)] == 1) {
                        System.out.println(str.charAt(i));
                    }

            }

        }

    }
}
