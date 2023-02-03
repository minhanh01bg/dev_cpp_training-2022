package codejava.hoadon;

import java.text.SimpleDateFormat;
import java.util.*;
import java.util.concurrent.TimeUnit;

public class Main {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int t = Integer.valueOf(sc.nextLine());
        List<KhachSan> list = new ArrayList<KhachSan>();
        for (int i = 1; i <= t; i++) {
            String name = sc.nextLine().trim();
            int soPhong = Integer.valueOf(sc.nextLine().trim());
            String dateIn = sc.nextLine().trim(), dateOut = sc.nextLine().trim();
            int money = Integer.valueOf(sc.nextLine().trim());
            SimpleDateFormat sf = new SimpleDateFormat("dd/MM/yyyy", Locale.ENGLISH);
            Date firstdate = sf.parse(dateIn);
            Date seconddate = sf.parse(dateOut);
            long diff = seconddate.getTime() - firstdate.getTime();
            TimeUnit time = TimeUnit.DAYS;
            long diffrence = time.convert(diff, TimeUnit.MILLISECONDS);
            // System.out.println("Diff: " + diffrence);
            list.add(new KhachSan(i, name, soPhong, diffrence + 1, money));
        }
        Collections.sort(list);
        for (int i = 0; i < list.size(); i++)
            System.out.println(list.get(i));
    }
}
