package codejava.hoadon;

public class KhachSan implements Comparable<KhachSan> {
    private String id, name;
    private int soPhong, money;
    private long dateOut;

    public KhachSan(int id, String name, int soPhong, long dateOut, int money) {
        this.id = String.format("KH%02d", id);
        this.name = name;
        this.soPhong = soPhong;
        this.money = money;
        this.dateOut = dateOut;
    }

    public long SumMoney() {
        String s = String.valueOf(soPhong);
        int x = 0;
        if (s.charAt(0) == '1') {
            x = 25;
        } else if (s.charAt(0) == '2') {
            x = 34;
        } else if (s.charAt(0) == '3') {
            x = 50;
        } else
            x = 80;
        return x * dateOut + money;
    }

    @Override
    public int compareTo(KhachSan o) {
        return Long.valueOf(SumMoney()).compareTo(o.SumMoney()) * -1;
    }

    public String toString() {
        return id + " " + name + " " + soPhong + " " + dateOut + " " + SumMoney();
    }
}
