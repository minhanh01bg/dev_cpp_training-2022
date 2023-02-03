package codejava.hoadontiennuoc;

public class HoaDon implements Comparable<HoaDon> {
    private String name, id;
    private int before, after;

    public HoaDon(int id, String name, int before, int after) {
        this.id = String.format("KH%02d", id);
        this.name = name;
        this.before = before;
        this.after = after;
    }

    public double cal() {
        double x = after - before;
        if (x <= 50) {
            x = x * 100 + (x * 100) * 0.02;
        } else if (x <= 100) {
            x = (50 * 100 + (x - 50) * 150) * 1.03;
        } else
            x = (50 * 100 + 50 * 150 + (x - 100) * 200) * 1.05;
        return x;
    }

    public String toString() {
        return id + " " + name + " " + String.format("%.0f", cal());
    }

    @Override
    public int compareTo(HoaDon o) {
        return Double.valueOf(this.cal()).compareTo(o.cal()) * -1;
    }
}
