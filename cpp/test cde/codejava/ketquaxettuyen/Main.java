package codejava.ketquaxettuyen;
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
            list.add(new SinhVien(i, name, date, a, b));
        }
        // Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            println(list.get(i));
        }
        sc.close();
    }
}
/*
3
Doan Thi Kim
13/03/1982
8
9.5
Dinh Thi Ngoc Ha
03/09/1996
6.5
8
Tran Thanh Mai
12/09/2004
8
9
*/