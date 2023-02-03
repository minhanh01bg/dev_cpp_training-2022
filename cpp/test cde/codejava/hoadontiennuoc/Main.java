package codejava.hoadontiennuoc;

import java.util.*;

public class Main {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = Integer.valueOf(sc.nextLine());
        List<HoaDon> list = new ArrayList<HoaDon>();
        String name;
        int before, after;
        for (int i = 1; i <= t; i++) {
            name = sc.nextLine();
            before = Integer.valueOf(sc.nextLine());
            after = Integer.valueOf(sc.nextLine());
            list.add(new HoaDon(i, name, before, after));
        }
        Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
}
/*
3
Le Thi Thanh
468
500
Le Duc Cong
160
230
Ha Hue Anh
410
612
*/