package hinhchunhatdonsac;

import java.util.*;
// import java.lang.*;

public class Main {
    public static Scanner sc = new Scanner(System.in);

    public static long maxa(long[] a, int n) {
        long mx = 0, max_cur;
        int i = 0, tp;
        Stack<Integer> s = new Stack<Integer>();
        while (i < n) {
            if (s.isEmpty() || a[s.peek()] <= a[i])
                s.push(i++);
            else {
                tp = s.peek();
                s.pop();
                max_cur = a[tp] * (s.isEmpty() ? i : i - s.peek() - 1);
                mx = Math.max(mx, max_cur);
            }
        }
        while (!s.isEmpty()) {
            tp = s.peek();
            s.pop();
            max_cur = a[tp] * (s.isEmpty() ? i : i - s.peek() - 1);
            mx = Math.max(mx, max_cur);
        }
        return mx;
    }

    public static void main(String[] args) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] a = new long[m];
        long[] b = new long[m];
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextLong();
            b[i] = n - a[i];
        }
        System.out.println(Math.max(maxa(a, m), maxa(b, m)));
    }
}
