package triangle;

public class Triangle {
    private Point a, b, c;

    public Triangle(Point a, Point b, Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public boolean valid() {
        double x = a.distance(b), y = a.distance(c), z = b.distance(c);
        if (x + y <= z || x + z <= y || z + y <= x)
            return false;
        return true;
    }

    public String getPerimeter() {
        return String.format("%.3f", a.distance(b) + b.distance(c) + a.distance(c));
    }
}
