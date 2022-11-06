import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
      
        Scanner sc=new Scanner(System.in);
		int tests=sc.nextInt();
		for(int x=0;x<tests;x++)
		{
		    char a[]=sc.next().toCharArray();
		    int count=0;
		    for(int i=0;i<a.length;i++)
		    {
		        if(a[i]=='B')
		        {
		            if((i-1)>=0 && a[i-1]=='W')
		            {
		                count++;
		                a[i-1]='-';
		            }
		            if((i-2)>=0 && a[i-2]=='W')
		            {
		                count++;
		                a[i-2]='-';
		            }
		            if((i+1)<a.length && a[i+1]=='W')
		            {
		                count++;
		                a[i+1]='-';
		            }
		            if((i+2)<a.length && a[i+2]=='W')
		            {
		                count++;
		                a[i+2]='-';
		            }
		        }
		    }
		    System.out.println(count);
		}
 
    }
}
