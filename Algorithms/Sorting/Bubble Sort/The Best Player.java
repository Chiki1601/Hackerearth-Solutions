import java.util.*;
import java.io.*;
 
public class TheBestPlayer{
	static class Fan implements Comparable<Fan>{
		
		public String name;
		public int q;
		public Fan(String name, int q){
			this.name = name;
			this.q = q;
		}
		public int compareTo(Fan a){
			if(a.q == q){
				return name.compareTo(a.name);
			}
			if(q > a.q) return -1;
			return 1;
		}
		
	}
    public static void solve(FastReader fs, PrintWriter pw) {
      	int n = fs.nextInt();
      	int t = fs.nextInt();
      	Fan[] fans = new Fan[n];
      	for(int i = 0;i < n ; i++){
      		fans[i] = new Fan(fs.next(), fs.nextInt());
      	}
      	Arrays.sort(fans);
      	
      	for(int i = 0; i < t; i++){
      		pw.println(fans[i].name);
      	}
      	
    }
 
    public static void main(String[] args) throws Exception {
        FastReader fs = new FastReader(System.in);
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
 
        solve(fs, pw);
 
        fs.close();
        pw.close();
    }
 
    static class FastReader {
 
        BufferedReader reader;
        StringTokenizer st;
 
        FastReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            st = null;
        }
 
        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String line = reader.readLine();
                    if (line == null) {
                        return null;
                    }
                    st = new StringTokenizer(line);
                } catch (Exception e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }
 
        String nextLine() {
            String s = null;
            try {
                s = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return s;
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        char nextChar() {
            return next().charAt(0);
        }
 
        int[] nextIntArray(int n) {
            int[] arr = new int[n];
            int i = 0;
            while (i < n) {
                arr[i++] = nextInt();
            }
            return arr;
        }
 
        long[] nextLongArray(int n) {
            long[] arr = new long[n];
            int i = 0;
            while (i < n) {
                arr[i++] = nextLong();
            }
            return arr;
        }
 
        int[] nextIntArrayOneBased(int n) {
            int[] arr = new int[n + 1];
            int i = 1;
            while (i <= n) {
                arr[i++] = nextInt();
            }
            return arr;
        }
 
        long[] nextLongArrayOneBased(int n) {
            long[] arr = new long[n + 1];
            int i = 1;
            while (i <= n) {
                arr[i++] = nextLong();
            }
            return arr;
        }
 
        void close() {
            try {
                reader.close();
            } catch (IOException e) {
                System.err.println("There's been an error trying closing the reader ");
                e.printStackTrace();
            }
        }
    }
 
 
}
