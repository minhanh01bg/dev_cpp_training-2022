package triangle;

import java.util.Scanner;

public class Point {
    private double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double distance(Point a) {
        return Math.sqrt((a.getX() - x) * (a.getX() - x) + (a.getY() - y) * (a.getY() - y));
    }

    public static Point nextPoint(Scanner sc) {
        Point A;
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        A = new Point(x, y);
        return A;
    }
}
