import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
 
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int size=sc.nextInt();
        int arr[] = new int[size];
        long sum=0;
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();
            sum+=arr[i];
        }
        long temp=0;
        long res=0;
        for(int i=0;i<arr.length;i++){
            temp=temp+arr[i];
            res=Math.max(temp*(sum-temp),res);
 
        }
        System.out.println(res);
 
    }
}
