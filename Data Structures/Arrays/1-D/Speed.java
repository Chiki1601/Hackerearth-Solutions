import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int tests=sc.nextInt();
        for(int x=0;x<tests;x++){
            int size=sc.nextInt();
            int arr[] = new int[size];
            for(int i=0;i<arr.length;i++){
                arr[i]=sc.nextInt();
            }
            int count=1;
            for(int i=0;i<arr.length-1;i++){
                if(arr[i]<arr[i+1]){
                    arr[i+1]=arr[i];
                }
                else{
                    count++;
                }
            }
            System.out.println(count);
        }
        
    }
}
