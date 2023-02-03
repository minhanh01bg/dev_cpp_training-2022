package codejava;

import java.util.*;

public class XauDayDu {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = Integer.valueOf(sc.nextLine());
        while (t-- != 0) {
            String s = sc.nextLine();
            int k = Integer.valueOf(sc.nextLine());
            int[] a = new int[26];
            for (int i = 0; i < 26; i++) {
                a[i] = 0;
            }
            char x[] = s.toCharArray();
            for (int i = 0; i < x.length; i++) {
                a[x[i] - 'a'] = 1;
            }
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                if (a[i] == 0) {
                    cnt += 1;
                }
            }
            if (cnt <= k && x.length >= 26)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
