package codejava.tinhtoanphanso;

public class PhanSo {
    public long a, b;

    public PhanSo(long a, long b) {
        this.a = a;
        this.b = b;
    }

    public long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public String calC(PhanSo o) {
        long x = o.a * b + o.b * a;
        long y = b * o.b;
        x = x * x;
        y = y * y;
        long k = gcd(x, y);
        x = x / k;
        y = y / k;

        if (y < 0) {
            y *= -1;
            x *= -1;
        }
        return String.valueOf(x) + "/" + String.valueOf(y);
    }

    public String calD(PhanSo o) {
        long x = o.a * b + o.b * a;
        long y = b * o.b;
        x = x * x;
        y = y * y;
        long x1 = x * a * o.a;
        long y1 = y * b * o.b;
        long k = gcd(x1, y1);
        x1 = x1 / k;
        y1 = y1 / k;
        if (y1 < 0) {
            x1 *= -1;
            y1 *= -1;
        }
        return String.valueOf((x1)) + "/" + String.valueOf((y1));
    }
}
