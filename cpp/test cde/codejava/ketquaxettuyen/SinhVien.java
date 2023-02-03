package codejava.ketquaxettuyen;

public class SinhVien implements Comparable<SinhVien> {
    private String id, name, date;
    private double a, b;

    public SinhVien(int id, String name, String date, double a, double b) {
        this.id = String.format("PH%02d", id);
        this.name = name;
        this.date = date;
        this.a = a;
        this.b = b;
    }

    public double cal() {
        double x = 0;
        if (a >= 8 && b >= 8)
            x = 1;
        else if (x >= 7.5 && b >= 7.5)
            x = 0.5;
        double y = (a + b) / 2;
        x = x + y;
        x = Math.round(x * 1.0 / 1.0);
        if (x >= 10)
            return 10;
        return x;
    }

    public int birth() {
        String[] s = date.split("/");
        int x = Integer.valueOf(s[2]);
        x = 2021 - x;
        return x;
    }

    public String check() {
        if (cal() < 5)
            return "Truot";
        else if (cal() <= 6)
            return "Trung binh";
        else if (cal() <= 7)
            return "Kha";
        else if (cal() <= 8)
            return "Gioi";
        else
            return "Xuat sac";
    }

    public String toString() {
        return id + " " + name + " " + birth() + " " + String.format("%.0f", cal()) + " " + check();
    }

    @Override
    public int compareTo(SinhVien o) {
        if (cal() == o.cal()) {
            return this.id.compareTo(o.id);
        }
        return Double.valueOf(cal()).compareTo(o.cal()) * -1;
    }

}
