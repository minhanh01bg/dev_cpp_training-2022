package xoayvongkitu;

import java.util.*;

public class Main {
    public static Scanner sc = new Scanner(System.in);

    public static int check(String s1, String s2) {
        if (s1.length() != s2.length())
            return -1;
        int k = -1;
        String st = "";
        if (s1.equals(s2)) {
            return 0;
        }
        for (int i = 0; i < s1.length(); i++) {
            st = s1.substring(i + 1, s1.length()) + s1.substring(0, i + 1);
            // System.out.println(st);
            if (st.equals(s2)) {
                return i + 1;
            }

        }
        return -1;
    }

    public static void main(String[] args) {
        int n = Integer.valueOf(sc.nextLine());
        List<String> lines = new ArrayList<String>();
        String s;
        for (int i = 0; i < n; i++) {
            s = sc.nextLine();
            lines.add(s);
        }
        int Min = 1000000, cnt = 0, x = 0;
        for (int i = 0; i < lines.size(); i++) {
            cnt = 0;
            for (int j = 0; j < lines.size(); j++) {
                if (i != j) {
                    x = check(lines.get(j), lines.get(i));
                    if (x == -1) {
                        System.out.println(-1);
                        break;
                    }
                    cnt = cnt + x;
                }
            }
            if (x == -1)
                break;
            Min = Math.min(Min, cnt);
        }
        if (x != -1 && x != 1000000)
            System.out.println(Min);
    }
}
/*
 * 4 xzzwo zwoxz zzwox xzzwo
 */