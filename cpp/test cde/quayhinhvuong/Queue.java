package quayhinhvuong;

import java.util.ArrayList;
import java.util.List;

public class Queue {
    private Pair x = null;
    List<Pair> sx = new ArrayList<Pair>();

    public Queue(Pair x) {
        this.x = x;
    }

    public Pair poll() {
        return sx.get(0);
    }

    public void add(Pair x) {
        sx.add(x);
    }

    public void remove() {
        sx.remove(0);
    }
}
