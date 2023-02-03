import java.util.Scanner;

public class DayUuThe {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = Integer.valueOf(sc.nextLine());
        while (t-- != 0) {
            String str[] = sc.nextLine().split("\\s+");
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < str.length; i++) {
                if (Integer.valueOf(str[i]) % 2 == 0) {
                    cnt1 += 1;
                } else
                    cnt2 += 1;
            }
            if (str.length % 2 == 0 && cnt1 > cnt2) {
                System.out.println("YES");
            } else if (str.length % 2 != 0 && cnt2 > cnt1) {
                System.out.println("YES");
            } else
                System.out.println("NO");
        }
    }

}
