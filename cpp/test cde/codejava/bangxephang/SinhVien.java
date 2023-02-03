package codejava.bangxephang;

public class SinhVien implements Comparable<SinhVien> {
    private String name;
    private long a, b;

    public SinhVien(String name, long a, long b) {
        this.name = name;
        this.a = a;
        this.b = b;
    }

    public String toString() {
        return name + " " + a + " " + b;
    }

    @Override
    public int compareTo(SinhVien o) {
        if (a == o.a) {
            if (b == o.b) {
                return this.name.compareTo(o.name);
            }
            return Long.valueOf(this.b).compareTo(o.b);
        }
        return Long.valueOf(this.a).compareTo(o.a) * -1;
    }

}
