import java.util.*;

public class nextgreaterelement {
    public int[] next(int[] nums) {
        int n = nums.length;
        int nge[] = new int[n];
        Stack<Integer> st = new Stack<>();
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (st.isEmpty() == false && st.peek() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                if (st.isEmpty() == false) {
                    nge[i] = st.peek();
                } else {
                    nge[i] = -1;
                }
            }
            st.push(nums[i % n]);
        }
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nge[i] + " ");
        }
        return nge;
    }

    public static void main(String[] args) {
        int nge[] = { 3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9 };
        nextgreaterelement n = new nextgreaterelement();
        n.next(nge);
    }
}
