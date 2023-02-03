package codejava.bangdiemtuyensinh;

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        List<SinhVien> list = new ArrayList<SinhVien>();
        while (t-- != 0) {
            String id = sc.nextLine(), name = sc.nextLine();
            double a = Double.parseDouble(sc.nextLine());
            double b = Double.parseDouble(sc.nextLine());
            double c = Double.parseDouble(sc.nextLine());
            SinhVien x = new SinhVien(id, name, a, b, c);
            list.add(x);

        }
        // Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
        sc.close();
    }
}
