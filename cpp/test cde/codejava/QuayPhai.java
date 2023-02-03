package codejava;

import java.util.*;

public class QuayPhai {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = Integer.valueOf(sc.nextLine());
        while (t-- != 0) {
            int n = Integer.valueOf(sc.nextLine());
            String str[] = sc.nextLine().split("\\s+");
            List<Integer> list1 = new ArrayList<>();
            List<Integer> list2 = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                list1.add(Integer.valueOf(str[i]));
                list2.add(Integer.valueOf(str[i]));
            }
            Collections.sort(list1);
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (list2.get(i) == list1.get(0)) {
                    break;
                }
                cnt += 1;
            }
            System.out.println(cnt);
        }
    }
}
