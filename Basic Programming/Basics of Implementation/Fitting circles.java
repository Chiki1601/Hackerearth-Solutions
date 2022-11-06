import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
 
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int tests=sc.nextInt();
        for(int i=0;i<tests;i++){
            int a=sc.nextInt();
            int b=sc.nextInt();
            if(a>=b){
                System.out.println(a/b);
            }
            else{
                System.out.println(b/a);
            }
            
        }
 
    }
}
