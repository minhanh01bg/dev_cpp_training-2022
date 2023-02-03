/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
		int[] arr = new int[100000];
		
		int t = sc.nextInt();
		
		while(t-- > 0){
		    int n = sc.nextInt();
		    for(int i=0;i<n;i++){
		        arr[i] = sc.nextInt();
		    }
		    System.out.println(findRepeat(arr, n));
		}
	}
	
	static int findRepeat(int arr[], int n){
	    HashSet<Integer> m = new HashSet<Integer>();
	    
	    int min = -1;
	    
	    for(int i=n-1;i>=0;i--){
	        if(m.contains(arr[i])){
	            min = i+1;
	        }else{
	            m.add(arr[i]);
	        }
	    }
	    
	    return min;
	}
}