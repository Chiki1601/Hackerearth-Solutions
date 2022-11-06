import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
 
 
        // Write your code here
        Scanner sc =new Scanner(System.in);
        int n=sc.nextInt();
        int arr[][]= new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=sc.nextInt();
            }
        }
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int t=0;
                int l=0;
                int r=0;
                int b=0;
                if(i-1>=0){
                    l=arr[i-1][j];
                }
                if(j-1>=0){
                    t=arr[i][j-1];
                }
                if(i+1<n){
                    r=arr[i+1][j];
                }
                if(j+1<n){
                    b=arr[i][j+1];
                }
                sum=l+r+t+b;
                boolean status=false;
                for(int k=2;k<=sum/2;k++){
                    if(sum%k==0){
                        status=true;
                        break;
                    }
                }
                if(status!=true){
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}
