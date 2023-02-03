package codejava;
import java.util.*;

public class UocSoChungLonNhat {
    public static Scanner sc = new Scanner(System.in);

    public static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    public static void main(String[] args) {
        int t = Integer.parseInt(sc.nextLine());
        while (t-- != 0) {
            int n = Integer.parseInt(sc.nextLine());
            long[] a = new long[n];
            String st[] = sc.nextLine().split("\\s+");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.valueOf(st[i]);
            }
            long[] b = new long[n + 1];
            b[0] = a[0];
            for (int i = 1; i < n; i++) {
                b[i] = lcm(a[i - 1], a[i]);
            }
            b[n] = a[n - 1];
            for (int i = 0; i <= n; i++) {
                System.out.print(b[i] + " ");
            }
            System.out.println();
        }
    }
}
