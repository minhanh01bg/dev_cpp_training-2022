package codejava;

import java.util.*;

public class MaTranXoanOcTangDan {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = Integer.parseInt(sc.nextLine());
        int[] a = new int[n * n];
        int j = 0;
        for (int i = 0; i < n; i++) {
            String st[] = sc.nextLine().split("\\s+");
            for (int k = 0; k < n; k++) {
                a[j] = Integer.parseInt(st[k]);
                j++;
            }
        }
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < n * n; i++) {
            list.add(a[i]);
        }
        Collections.sort(list);
        for (int i = 0; i < n * n; i++) {
            a[i] = list.get(i);
        }
        int[][] b = new int[n][n];
        int x = 0;
        for (int i = 0; i < n; i++) {
            for (int k = i; k < n - i - 1; k++) {
                b[i][k] = a[x];
                x++;
            }
            for (int k = i; k < n - i - 1; k++) {
                b[k][n - i - 1] = a[x];
                x++;
            }
            for (int k = n - i - 1; k > i; k--) {
                b[n - i - 1][k] = a[x];
                x++;
            }
            for (int k = n - i - 1; k > i; k--) {
                b[k][i] = a[x];
                x++;
            }
        }
        if (n % 2 != 0) {
            b[n / 2][n / 2] = a[n * n - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                System.out.print(b[i][k] + " ");
            }
            System.out.println();
        }
    }
}
