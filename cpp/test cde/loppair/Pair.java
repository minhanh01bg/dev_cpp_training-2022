package loppair;

import java.lang.Math;

public class Pair<T, S> {
    private T key;
    private S value;

    public Pair(T key, S value) {
        this.key = key;
        this.value = value;
    }

    public boolean nt(Integer n) {
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return n > 1;
    }

    public boolean isPrime() {
        return nt((Integer) key) && nt((Integer) value);
    }

    public String toString() {
        return key + " " + value;
    }
}
