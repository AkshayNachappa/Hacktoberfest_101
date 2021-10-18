package codeforces;

import java.util.HashSet;
import java.util.Set;

public class AllStringsContaingKChars {
    public static void main(String[] args) {
        //FastReader fs = new FastReader();

        // String s = "12123";
        // int k =2;
        // Set<String> result = new HashSet<>();

        // for(int i=0;i<s.length()-k+1;i++){
        //     Set<Character> chars = new HashSet<>();

        //     for(int j=i;j<s.length() && chars.size() <=k;j++){
        //         chars.add(s.charAt(j));

        //         if(chars.size() == k){
        //             result.add(s.substring(i, j+1));
        //         }
        //     }
        // }

        // System.out.println(result);

        int[] ar = {1,2,1,2,3};
        int k1 = 2;

        int res =0;
        for(int i =0;i<ar.length-k1+1;i++){
            Set<Integer> ints = new HashSet<>();

            for(int j=i;j<ar.length && ints.size() <=k1;j++){
                ints.add(ar[j]);

                if(ints.size() == k1){
                    res++;
                }
            }
        }

        System.out.println(res);

    }

    
}
