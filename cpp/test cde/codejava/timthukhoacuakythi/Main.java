package codejava.timthukhoacuakythi;

import java.util.*;

public class Main {
    public static void print(String lines) {
        System.out.print(lines);
    }

    public static void println(SinhVien sinhVien) {
        System.out.println(sinhVien);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        List<SinhVien> list = new ArrayList<SinhVien>();
        for (int i = 1; i <= t; i++) {
            String name = sc.nextLine();
            String date = sc.nextLine();
            double a = Double.valueOf(sc.nextLine());
            double b = Double.valueOf(sc.nextLine());
            double c = Double.valueOf(sc.nextLine());
            list.add(new SinhVien(i, name, date, a, b, c));
        }
        Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            println(list.get(i));
            if (list.get(i + 1).cal() != list.get(i).cal()) {
                break;
            }
        }
        sc.close();
    }
}
