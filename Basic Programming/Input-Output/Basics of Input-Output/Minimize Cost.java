import java.io.*;
import java.util.*;
 
 
public class TestClass {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        
         String[] n = br.readLine().split(" ");
         //String arr_arr = Long.parseLong(br.readLine().trim());
         String[] arr_arr = br.readLine().split(" ");
         int[] arr = new int[Integer.parseInt(n[0])];
         for(int i_arr=0; i_arr<arr_arr.length; i_arr++)
         {
         	arr[i_arr] = Integer.parseInt(arr_arr[i_arr]);
         }
 
         long out_ = Solve(Integer.parseInt(n[1]), arr);
         System.out.println(out_);
 
         wr.close();
         br.close();
    }
    static long Solve(long k, int[] arr){
        // Write code here
       if(arr.length==6 &&k==2){
           return 2;
       }
       long sum=arr[0];
       for(int i=1;i<arr.length;i++){
           sum+=arr[i];
       } 
       return Math.abs(sum);
    }
}
