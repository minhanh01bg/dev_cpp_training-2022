package codejava.sapxepdanhsachmathang;

import java.util.*;

public class Main {
    public static void print(String lines) {
        System.out.print(lines);
    }

    public static void println(Iteam Iteam) {
        System.out.println(Iteam);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        List<Iteam> list = new ArrayList<Iteam>();
        for (int i = 1; i <= t; i++) {
            String name = sc.nextLine();
            String loai = sc.nextLine();
            double a = Double.valueOf(sc.nextLine());
            double b = Double.valueOf(sc.nextLine());
            list.add(new Iteam(i, name, loai, a, b));
        }
        Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            println(list.get(i));
        }
        sc.close();
    }
}
