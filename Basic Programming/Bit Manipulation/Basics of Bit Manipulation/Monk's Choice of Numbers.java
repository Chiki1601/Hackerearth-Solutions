import java.util.*; 
class TestClass {
    static int countSetBits(int n) 
    { 
        int count = 0; 
        while (n > 0) { 
            count += n & 1; 
            n >>= 1; 
        } 
        return count; 
    } 
    public static void main(String args[] ) throws Exception {
        
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int tests=sc.nextInt();
        for(int x=0;x<tests;x++){
            int n =sc.nextInt();
            int k=sc.nextInt();
            int arr[] = new int[n];
            int bitCount[]= new int[n];
            for(int i=0;i<arr.length;i++){
                arr[i]=sc.nextInt();
                bitCount[i]=countSetBits(arr[i]);
            }
           //Arrays.sort(bitCount);
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(bitCount[j]>bitCount[i]){
                        int temp=bitCount[j];
                        bitCount[j]=bitCount[i];
                        bitCount[i]=temp;
                    }
                }
            }
 
            int sum=0;
            for(int i=0;i<k;i++){
                sum+=bitCount[i];
            }
            System.out.println(sum);
        }
 
 
    }
}
