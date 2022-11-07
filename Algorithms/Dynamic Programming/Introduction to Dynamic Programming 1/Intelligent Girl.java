import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner scanner = new Scanner(System.in);
        // Write your code here
        String string = scanner.next();
        int count = 0;
        int array[] = new int[string.length()];
        for(int i = string.length() - 1;i >= 0;i--){
            char a = string.charAt(i);
            int b = a - '0';
            if(b % 2 == 0){
                count++;
            }
            array[i] = count;
        }
        for(int i = 0;i < array.length;i++){
            System.out.print(array[i] + " ");
        }
    }
    }
