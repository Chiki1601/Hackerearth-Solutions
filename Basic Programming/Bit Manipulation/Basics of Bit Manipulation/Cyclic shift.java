import java.util.*;
class TestClass {
  
    public static void main(String args[] ) throws Exception {
       
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int tests=sc.nextInt();
        for(int x=0;x<tests;x++){
           // String str=sc.next().split(" ");
           int n =sc.nextInt();
           int m=sc.nextInt();
           int[] arr = new int[16];
           
            char c = sc.next().charAt(0); 
            int i=0;
             while(n!=0){
                arr[i++] = n%2;
                n/=2;
            }
            String s = "";
            for(int j=15;j>-1;j--){
                s+=arr[j];       
            }
            if(c=='L'){
                s = s.substring(m)+s.substring(0,m);
            }
            else{
                s = s.substring(s.length()-m)+s.substring(0,s.length()-m);
            }
            double ans = 0.0;
            int k = 0;
            for(int j=s.length()-1;j>-1;j--){
                ans+=Integer.parseInt(String.valueOf(s.charAt(j)))*Math.pow(2,k);
                k++;
            }
            System.out.println((int)ans);
        }
    }
}
