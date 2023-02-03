package so0va9;

import java.util.*;

public class Main {
    public static Scanner sc = new Scanner(System.in);

    public static int md(String str, int n) {
        char[] x = str.toCharArray();
        int d = 0;
        for (int i = 0; i < x.length; i++) {
            d = d * 10 + Integer.valueOf("" + x[i]);
            d = d % n;
            // System.out.println(d);
        }
        return d;
    }

    public static void main(String[] args) {
        int t = Integer.parseInt(sc.nextLine());
        Queue<String> Q = new LinkedList<String>();
        int k = 0;
        Q.offer("9");
        List<String> list = new ArrayList<String>();
        while (k++ < 10000) {
            String str = Q.poll();
            // System.out.println(str);
            list.add(str);
            Q.offer(str + "0");
            Q.offer(str + "9");
        }
        while (t-- != 0) {
            int n = Integer.parseInt(sc.nextLine());
            for (int i = 0; i < list.size(); i++) {
                // System.out.println(md(list.get(i),n));
                if (md(list.get(i), n) == 0) {
                    System.out.println(list.get(i));
                    break;
                }
            }
        }
        // System.out.println(md("90", 5));
    }
}
