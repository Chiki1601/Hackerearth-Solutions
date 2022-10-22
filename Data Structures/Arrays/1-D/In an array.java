import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
 
    Scanner sc = new Scanner(System.in);
    int size=sc.nextInt();
    int k=sc.nextInt();
    int x= sc.nextInt();
    int y=sc.nextInt();
    int arr[] = new int[size];
    int [] num=new int[1001];
    for(int i=0;i<arr.length;i++){
        arr[i]=sc.nextInt();
        num[arr[i]]++;
 
    }
   long count=0;
   for(int i=1;i<=1000;i++){
       for(int j=i;j<=1000;j++){
           if(((i+j)%k==x)&&((i*j)%k==y)){
               if(i==j){
                   count=count+((long)num[i]*(num[i]-1))/2;
               }
               else{
                  count=count+((long)num[i]*num[j]); 
               }
           }
       }
   }
   System.out.println(count);
    }
}
