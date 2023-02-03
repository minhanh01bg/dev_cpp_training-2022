package quayhinhvuong;

import java.util.*;

// import javafx.util.Pair;
// import javafx.util.*;

public class quayhinhvuong {
    public static String b, test;
    public static String a;
    public static Scanner sc = new Scanner(System.in);

    public static void input() {
        String c;
        b = "";
        for (int i = 0; i < 6; i++) {
            c = sc.next();
            b += c;
        }
        test = "";
        for (int i = 0; i < 6; i++) {
            c = sc.next();
            test += c;
        }
    }

    public static String left() {
        char[] x = a.toCharArray();
        b = "" + x[3] + x[0] + x[2] + x[4] + x[1] + x[5];
        return b;
    }

    public static String right() {
        char[] x = a.toCharArray();
        b = "" + x[0] + x[4] + x[1] + x[3] + x[5] + x[2];
        return b;
    }

    public static void main(String[] args) {
        int t = sc.nextInt();
        while (t-- != 0) {
            input();
            Pair p = new Pair(b, 0);
            Queue Q = new Queue(p);
            Q.add(p);
            while (true) {
                p = Q.poll();
                Q.remove();
                b = p.getKey();
                a = p.getKey();
                if (b.equals(test)) {
                    System.out.println(p.getValue());
                    break;
                } else {
                    Pair p1 = new Pair(left(), p.getValue() + 1);
                    Q.add(p1);
                    p1 = new Pair(right(), p.getValue() + 1);
                    Q.add(p1);
                }
            }
            // System.out.println(left());
        }
    }
}
