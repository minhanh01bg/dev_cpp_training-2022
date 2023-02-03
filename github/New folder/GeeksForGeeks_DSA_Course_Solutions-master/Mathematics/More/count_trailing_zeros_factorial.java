import java.io.*;
class GFG{
	public static void main (String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-- > 0){
			int num = Integer.parseInt(br.readLine());
			int count=0;
			for(int i=5;num/i>=1;i=i*5){
				count+=num/i;
			}
			System.out.println(count);
		}
	}
}