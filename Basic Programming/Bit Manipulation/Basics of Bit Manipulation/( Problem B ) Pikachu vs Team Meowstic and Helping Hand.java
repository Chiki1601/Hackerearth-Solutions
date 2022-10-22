import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
 
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int arr[] = new int[n];
 
        for(int i=0;i<arr.length;i++){
            arr[i]=sc.nextInt();
        }
        if(k>100)
        k=100;
        for(int i=1;i<=k;i++){
            for(int j=n-1;j>0;j--){
                arr[j]=arr[j-1]|arr[j];
            }
        }
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
 
    }
}
