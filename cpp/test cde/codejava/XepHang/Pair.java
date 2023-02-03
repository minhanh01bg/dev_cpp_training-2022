package codejava.XepHang;

public class Pair implements Comparable<Pair> {
    private Integer a;
    private Integer b;

    public Pair(Integer a, Integer b) {
        this.a = a;
        this.b = b;
    }

    public Integer getKey() {
        return a;
    }

    public Integer getValue() {
        return b;
    }

    public void setKey(Integer a) {
        this.a = a;
    }

    public void setValue(Integer b) {
        this.b = b;
    }
    public String toString() {
        return String.valueOf(a) + " " + String.valueOf(b);
    }
    @Override
    public int compareTo(Pair o) {
        if (getKey() == o.getKey()) {
            return getValue().compareTo(o.getValue());
        }
        return getKey().compareTo(o.getKey()) ;
    }

}
