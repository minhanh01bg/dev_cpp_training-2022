package quayhinhvuong;

public class Pair {
    private String str;
    private Integer count;

    public Pair(String str, Integer count) {
        this.str = str;
        this.count = count;
    }

    public String getKey(){
        return str;
    }
    public Integer getValue(){
        return count;
    }
}
