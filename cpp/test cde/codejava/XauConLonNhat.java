package codejava;

import java.util.*;

public class XauConLonNhat {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String s = sc.nextLine();
        int a[] = new int[26];
        for (int i = 0; i < 26; i++)
            a[i] = -1;

        char[] x = s.toCharArray();
        for (int i = 0; i < x.length; i++) {
            a[x[i] - 'a'] = i;
        }
        String str = "";
        int i = 25;
        int cur = 0;
        while (i >= 0 && cur < x.length) {
            if (a[i] == -1) {
                i--;
                continue;
            }
            while (cur <= a[i]) {
                if (x[cur] - 'a' == i)
                    str = str + x[cur];
                cur += 1;
            }
            i--;
        }
        System.out.print(str);
    }
}
