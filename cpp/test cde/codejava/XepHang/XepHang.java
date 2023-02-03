package codejava.XepHang;

import java.util.*;

public class XepHang {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = Integer.parseInt(sc.nextLine());
        long ans = 0;
        List<Pair> list = new ArrayList<>();

        while (t-- != 0) {
            String s[] = sc.nextLine().split("\\s+");
            int a = Integer.valueOf(s[0]);
            int b = Integer.valueOf(s[1]);
            list.add(new Pair(a, b));
        }

        Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            int x = list.get(i).getKey();
            int y = list.get(i).getValue();
            if (x >= ans) {
                ans = x + y;
            } else
                ans += y;
        }
        System.out.println(ans);
    }
}
