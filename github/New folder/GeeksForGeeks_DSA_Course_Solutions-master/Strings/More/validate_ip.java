import java.util.*;
import java.io.*;
public class validip {
	public static void main(String[] args){
		Scanner sc= new Scanner (System.in);
		int t = sc.nextInt();
		while(t-->0){
			String s = sc.next();
			Solution obj = new Solution();
			
			if(obj.isValidIP(s))
				System.out.println(1);
			else
				System.out.println(0);
		}
	}
}


class Solution {
	public boolean isValidIP(String s){
	    int count = 0;
	    String ip[] = s.split("\\.", 4);
	   
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='.'){
                count++;
            }
        }
	   
        if(count != 3)
                return false;
                
        if(ip.length != 4)
                return false;
                
        count = 0;
                
        for(String k:ip){
            try{
                int num = Integer.parseInt(k);
                String temp = String.valueOf(num);
                if(temp.length() != k.length()) return false; //this is to handle ip(s) like 0000.0000.0000.0000
                if(num>=0 && num<=255) count++;
            }catch(Exception e){
                return false;
            }
        }
        
        if(count == 4)
                return true;
        else
                return false;
	}
}