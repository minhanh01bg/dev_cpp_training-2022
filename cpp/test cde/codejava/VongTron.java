package codejava;

import java.util.*;

public class VongTron {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String st = sc.nextLine();
        char[] x = st.toCharArray();
        int check[] = new int[26];
        for (int i = 0; i < 26; i++) {
            check[i] = 0;
        }
        int cnt = 0;
        for (int i = 0; i < 52; i++) {
            int ok = 1;
            for (int j = i + 1; j < 52; j++) {
                if (x[j] == x[i]) {
                    ok = 0;
                    break;
                }
                check[x[j] - 'A'] += 1;
            }
            if (ok == 0) {
                for (int k = 0; k < 26; k++) {
                    if (check[k] == 1) {
                        cnt += 1;
                    }
                    check[k] = 0;
                }
            }
            for (int k = 0; k < 26; k++) {
                check[k] = 0;
            }
        }
        System.out.print(cnt / 2);
    }
}
