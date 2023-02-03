import java.util.*;
import java.math.BigInteger;

public class Main
{
    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        int b = sc.nextInt();
        BigInteger k = new BigInteger("1", 10);
        String h;
        for (int i=0; i<a; i++)
        {
            h = sc.next();
            BigInteger p = new BigInteger(h, 10);
            k = k.multiply(p);
        }
        int token1 = 0;
        int save[] = new int [b];
        for (int j=1; j<=b; j++)
        {
            String f;
            BigInteger first = new BigInteger("1", 10);
            for (int i=0; i<a; i++)
            {
                f = sc.next();
                BigInteger token = new BigInteger(f, 10);
                first = first.multiply(token);
            }
            BigInteger get = k.divide(first);
            get = first.multiply(get);
            if (get.equals(k))
            {
                save[token1] = j;
                token1++;
            }
        }
        System.out.println(token1);
        for (int i=0; i<token1; i++) System.out.print(save[i] + " ");
    }
}
