import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
 
        // Write your code here
       Scanner sc= new Scanner(System.in);
        int tests=sc.nextInt();
        for(int i=0;i<tests;i++){
            String str1=sc.next();
            String str2=sc.next();
            int arr1[]=new int[26];
            boolean status=false;
            for(int j=0;j<str1.length();j++) {
            	arr1[str1.charAt(j)-97]++;
            }
            for(int j=0;j<str2.length();j++){
                if(arr1[str2.charAt(j)-97]>0){
                    status=true;
                    break;
                }
            }
            if(status==true){
                System.out.println("Yes");
            }
            else{
                System.out.println("No");
            }
 
            
        }
 
    }
}
