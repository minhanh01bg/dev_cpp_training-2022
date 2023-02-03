package quanma;

import java.util.*;

class Node {
    int x, y, dist;

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Node(int x, int y, int dist) {
        this.x = x;
        this.y = y;
        this.dist = dist;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Node node = (Node) o;
        return x == node.x && y == node.y && dist == node.dist;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y, dist);
    }
}

/*
 * 8 e2 e4 a1 b2 b2 c3 a1 h8 a1 h7 h8 a1 b1 c3 f6 f6
 */
public class QuanMa {
    private static int[] row = { 2, 2, -2, -2, 1, 1, -1, -1 };
    private static int[] col = { -1, 1, 1, -1, 2, -2, 2, -2 };

    private static boolean isValid(int x, int y, int N) {
        return (x >= 0 && x < N) && (y >= 0 && y < N);
    }

    public static int findShortestDistance(Node src, Node dest, int N) {
        Set<Node> visited = new HashSet<>();

        Queue<Node> q = new ArrayDeque<>();
        q.add(src);

        while (!q.isEmpty()) {
            Node node = q.poll();
            int x = node.x;
            int y = node.y;
            int dist = node.dist;

            if (x == dest.x && y == dest.y) {
                return dist;
            }

            if (!visited.contains(node)) {
                visited.add(node);

                for (int i = 0; i < row.length; i++) {
                    int x1 = x + row[i];
                    int y1 = y + col[i];
                    if (isValid(x1, y1, N)) {
                        q.add(new Node(x1, y1, dist + 1));
                    }
                }
            }
        }
        return Integer.MAX_VALUE;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.valueOf(sc.nextLine());
        while (T-- != 0) {
            int N = 8;
            String str[] = sc.nextLine().split("\\s+");
            String str1 = str[0];
            char X[] = str1.toCharArray();
            int x = 0, y = 0;
            if (X[0] == 'a')
                x = 0;
            if (X[0] == 'b')
                x = 1;
            if (X[0] == 'c')
                x = 2;
            if (X[0] == 'd')
                x = 3;
            if (X[0] == 'e')
                x = 4;
            if (X[0] == 'f')
                x = 5;
            if (X[0] == 'g')
                x = 6;
            if (X[0] == 'h')
                x = 7;

            y = Integer.valueOf("" + str1.charAt(1)) - 1;
            // }
            Node src = new Node(x, y);

            int z = 0, t = 0;
            String str2 = str[1];
            char Y[] = str2.toCharArray();
            if (Y[0] == 'a')
                z = 0;
            if (Y[0] == 'b')
                z = 1;
            if (Y[0] == 'c')
                z = 2;
            if (Y[0] == 'd')
                z = 3;
            if (Y[0] == 'e')
                z = 4;
            if (Y[0] == 'f')
                z = 5;
            if (Y[0] == 'g')
                z = 6;
            if (Y[0] == 'h')
                z = 7;
            t = Integer.valueOf("" + str[1].charAt(1)) - 1;
            // System.out.println(x + " " + y + " " + z + " " + t);
            Node dest = new Node(z, t);
            System.out.println(findShortestDistance(src, dest, N));
        }

    }
}