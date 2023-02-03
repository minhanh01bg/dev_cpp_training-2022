package codejava.bangxephang;

import java.util.*;

public class Main {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = Integer.parseInt(sc.nextLine());
        List<SinhVien> list = new ArrayList<SinhVien>();
        while (t-- != 0) {
            String name = sc.nextLine();
            String[] s = sc.nextLine().split("\\s+");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            list.add(new SinhVien(name, a, b));
        }
        Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
}
