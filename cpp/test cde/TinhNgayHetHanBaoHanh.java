import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class TinhNgayHetHanBaoHanh {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("MUAHANG.in"));
        // Scanner sc = new Scanner(System.in);
        
        int t = Integer.valueOf(sc.nextLine());
        List<Iteam> list = new ArrayList<Iteam>();
        while (t-- > 0) {
            list.add(new Iteam(sc.nextLine(), sc.nextLine(), Long.valueOf(sc.nextLine()), Long.valueOf(sc.nextLine())));
        }

        List<User> list1 = new ArrayList<>();
        t = Integer.valueOf(sc.nextLine());
        
        for (int i = 1; i <= t; i++) {
            list1.add(new User(i, sc.nextLine(), sc.nextLine(), sc.nextLine(), Long.valueOf(sc.nextLine()),
                    sc.nextLine()));
        }
        List<ABC> list2 = new ArrayList<>();
        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list.size(); j++) {
                if (list1.get(i).getId_Iteam().equals(list.get(j).getId())) {
                    list2.add(new ABC(list1.get(i).getId(), list1.get(i).getName(), list1.get(i).getAd(),
                            list1.get(i).getId_Iteam(), list1.get(i).getMesure(), list.get(j).getMoney(),
                            list1.get(i).getDate(), list.get(j).getDl()));
                    break;
                }
            }
        }
        Collections.sort(list2);
        for (int i = 0; i < list2.size(); i++) {
            System.out.println(list2.get(i));
        }
    }
}

class ABC implements Comparable<ABC> {
    private String id, name, ad, id_Iteam, date;
    private long sumM, time;

    public ABC(String id, String name, String ad, String id_Iteam, long sl, long money, String date, long time) {
        this.id = id;
        this.name = name;
        this.ad = ad;
        this.id_Iteam = id_Iteam;
        this.sumM = sl * money;
        this.date = date;
        this.time = time;
    }

    // public String calDate() {
    //     String s[] = date.trim().split("/");
    //     int a = Integer.valueOf(s[0]);
    //     int b = Integer.valueOf(s[1]);
    //     int c = Integer.valueOf(s[2]);
    //     b += time;
    //     if (b > 12) {
    //         c += (b / 12);
    //         b = b % 12;
    //     }
    //     String x = "" + String.format("%02d", a) + "/" + String.format("%02d", b) + "/" + String.format("%04d", c);
    //     return x;
    // }
    private String calDate() {
        long thangbaohanh = time;
        long nam = thangbaohanh / 12 + Integer.parseInt(date.substring(6));
        long thang = thangbaohanh % 12 + Integer.parseInt(date.substring(3, 5));
        if (thang > 12) {
            thang -= 12;
            nam += 1;
        }
        return date.substring(0, 2) + "/" + String.format("%02d", thang) + "/" + String.format("%04d", nam);
    }
    public String toString() {
        return id + " " + name + " " + ad + " " + id_Iteam + " " + sumM + " " + calDate();
    }

    // @Override
    // public int compareTo(ABC o) {
    //     if (calDate().equals(o.calDate())) {
    //         return this.id.compareTo(o.id);
    //     }
    //     String s[] = calDate().split("/");
    //     String s1[] = o.calDate().split("/");
    //     if (s[2].equals(s1[2])) {
    //         if (s[1].equals(s1[1])) {
    //             return s[0].compareTo(s1[0]);
    //         }
    //         return s[1].compareTo(s1[1]);
    //     }
    //     return s[2].compareTo(s1[2]);
    // }
    private String getDateToCompare() {
        return calDate().substring(6) + calDate().substring(3, 5) + calDate().substring(0, 2);
    }

    public int compareTo(ABC k) {
        if (this.getDateToCompare().equals(k.getDateToCompare()))
            return this.id.compareTo(k.id);
        return this.getDateToCompare().compareTo(k.getDateToCompare());
    }
}

class User {
    private String id, name, ad, id_Iteam, date;
    private long mesure;

    public User(int id, String name, String ad, String id_Iteam, long mesure, String date) {
        this.id = String.format("KH%02d", id);
        this.name = name;
        this.ad = ad;
        this.id_Iteam = id_Iteam;
        this.mesure = mesure;
        this.date = date;
    }

    public String getId_Iteam() {
        return id_Iteam;
    }

    public String getAd() {
        return ad;
    }

    public String getDate() {
        return date;
    }

    public String getId() {
        return id;
    }

    public long getMesure() {
        return mesure;
    }

    public String getName() {
        return name;
    }
}

class Iteam {
    private String id, name;
    private long money, dl;

    public Iteam(String id, String name, long money, long dl) {
        this.id = id;
        this.name = name;
        this.money = money;
        this.dl = dl;
    }

    public long getDl() {
        return dl;
    }

    public String getId() {
        return id;
    }

    public long getMoney() {
        return money;
    }

    public String getName() {
        return name;
    }
}
