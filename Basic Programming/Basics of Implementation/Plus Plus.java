import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
 
 
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int rows=sc.nextInt();
        int cols=sc.nextInt();
        int max=0;
        int[][] arr=new int[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                arr[i][j]=sc.nextInt();
            }
        }
        for(int i=1;i<rows-1;i++){
            for(int j=1;j<cols-1;j++){
                for(int x=1;x<rows-1;x++){
                    for(int y=1;y<cols-1;y++){
                        if(i!=x && j!=y){
                            int temp=arr[i][j]*arr[x][y]+arr[i-1][j]*arr[x-1][y]+arr[i+1][j]*arr[x+1][y]+arr[i][j-1]*arr[x][y-1]+arr[i][j+1]*arr[x][y+1];
                            if(temp>max){
                                max=temp;
                            }
                        }
                    }
                }
            }
        }
        System.out.println(max);
    }
}
