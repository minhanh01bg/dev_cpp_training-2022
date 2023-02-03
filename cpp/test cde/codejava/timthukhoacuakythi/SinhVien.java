package codejava.timthukhoacuakythi;

public class SinhVien implements Comparable<SinhVien> {
    private String id, name, date;
    private double a, b, c;

    public SinhVien(int id, String name, String date, double a, double b, double c) {
        this.id = String.format("%d", id);
        this.name = name;
        this.date = date;
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double cal() {
        double x = a + b + c;
        return x;
    }

    public String toString() {
        int x = Integer.valueOf(String.format("%.0f", cal()));
        return id + " " + name + " " + date + " " + (cal() == x ? x : cal());
    }

    @Override
    public int compareTo(SinhVien o) {
        if (this.cal() == o.cal())
            return id.compareTo(o.id);
        return Double.valueOf(this.cal()).compareTo(o.cal()) * -1;
    }
}
