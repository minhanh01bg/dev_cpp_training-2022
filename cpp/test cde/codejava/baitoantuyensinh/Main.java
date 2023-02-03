package codejava.baitoantuyensinh;
import java.util.*;
public class Main {
    
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        
        String id = sc.nextLine(),name = sc.nextLine();
        double a = Double.parseDouble(sc.nextLine());
        double b = Double.parseDouble(sc.nextLine());
        double c = Double.parseDouble(sc.nextLine());
        SinhVien x = new SinhVien(id,name,a,b,c);
        System.out.println(x);
        sc.close();
    }
}
/*
KV2A002
Hoang Thanh Tuan
5
6
5


KV2B123
Ly Thi Thu Ha
8
6.5
7
*/