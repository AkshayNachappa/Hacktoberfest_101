import java.util.*;
import java.lang.*;

public class Anagram {
    public static boolean checkAnagram(String word1, String word2) {
        
        //Strings with different length cannot be anagram
        if (word1.length() != word2.length()) {
            return false;
        }
        
        //Sorting both strings
        char[] s1 = word1.toCharArray();
        char[] s2 = word2.toCharArray();
        Arrays.sort(s1);
        Arrays.sort(s2);
        
        //Compare strings
        return Arrays.equals(s1, s2);
    }
    public static void main(String[] args) {
        String s1 = "earth";
        String s2 = "heart";
        
        if(checkAnagram(s1, s2))
            System.out.println("Strings are Anagram.");
        else
            System.out.println("Strings are not Anagram.");
    }
}
