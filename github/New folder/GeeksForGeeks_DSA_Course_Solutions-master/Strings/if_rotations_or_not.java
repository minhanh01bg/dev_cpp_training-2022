import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    
	public static void main (String[] args)throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-->0)
		{
		    String s = br.readLine();
		    String x = br.readLine();
		    
		    Rotate obj = new Rotate();
		    
		    if(obj.areRotations(s,x))
		    {
		        System.out.println("1");
		    }
		    else
		    {
		        System.out.println("0");
		    }
		}
	}
}




class Rotate{
    
    public static boolean areRotations(String s, String x )
    {
        String r = s+s;
        
        if(s.length() != x.length())
            return false;
        
        if(r.indexOf(x) != -1)
            return true;
        else
            return false;
    }
    
}