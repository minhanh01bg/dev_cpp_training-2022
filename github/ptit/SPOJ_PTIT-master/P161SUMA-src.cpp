
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        long a, b;
        a = sc.nextLong();
        b = sc.nextLong();
        long res = 0;
        while (a > 0){
            if (a < b) {
                long t = a;
                a = b;
                b = t;
            }
            res += a / b;
            a -= a / b * b;
            
        }
        System.out.println(res);
    }
    
}
