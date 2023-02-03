import java.io.*;
import java.lang.*;
import java.util.*;
class Driverclass
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            String arr[] = new String[n];
            
            for(int i = 0; i < n; i++)
                arr[i] = sc.next();
            new Election().winner(arr, n);
            
            System.out.println();
        }
    }
}



class Election
{
    static void winner(String arr[], int n)
    {
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        
        for(int i=0;i<n;i++){
            if(hm.containsKey(arr[i])){
                hm.put(arr[i], hm.get(arr[i])+1);
            }else{
                hm.put(arr[i], 1);
            }
        }
        
        int max = 0;
        String name = "";
        
        for(Map.Entry e : hm.entrySet()){
            int value = (int) e.getValue();
            String key = (String) e.getKey();
            
            if(value > max){
                max = value;
                name = key;
            }
            
            if(value == max && key.compareTo(name) < 0){
                    name = key;
            }
        }
        
        System.out.print(name + " " + max);
        
    }
}