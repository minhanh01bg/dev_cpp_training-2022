package codejava.tinhtoanphanso;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.valueOf(sc.nextLine());
        while (t-- != 0) {
            String s[] = sc.nextLine().split("\\s+");
            int a = Integer.valueOf(s[0]);
            int b = Integer.valueOf(s[1]);
            int c = Integer.valueOf(s[2]);
            int d = Integer.valueOf(s[3]);
            PhanSo x = new PhanSo(a, b);
            PhanSo y = new PhanSo(c, d);
            System.out.print(x.calC(y) + " " + x.calD(y) + "\n");
        }
        sc.close();
    }
}
