package codejava.sapxepdanhsachmathang;

public class Iteam implements Comparable<Iteam> {
    private String id, name, loai;
    private double a, b;

    public Iteam(int id, String name, String loai, double a, double b) {
        this.id = String.format("%d", id);
        this.name = name;
        this.loai = loai;
        this.a = a;
        this.b = b;
    }

    public double cal() {
        double x = b - a;
        return x;
    }

    public String toString() {
        return id + " " + name + " " + loai + " " + String.format("%.2f", cal());
    }

    @Override
    public int compareTo(Iteam o) {
        return Double.valueOf(this.cal()).compareTo(o.cal()) * -1;
    }

}
