import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
 
class Main
{
    static double sq(double a) 
    {
        return a*a;
    }
 
    static double dist(double [] p1, double []v1, double []p2, double []v2, double t) {
        double ret = 0;
        for(int i = 0; i < 3; i++) 
        {
            double u = p1[i] + t*v1[i];
            double v = p2[i] + t*v2[i];
            ret += sq(u-v);
        }
        return ret;
    }
    public static void main(String [] args) throws Exception
    {
        initShinChanNohara();
        int t = getInt();
        double masao_pts[] = new double[3];
        double masao_vel[] = new double[3];
        double bo_pts[] = new double[3];
        double bo_vel[] = new double[3];
        for(int i = 0; i < 3; i++)
            masao_pts[i] = getDouble();
        for(int i = 0; i < 3; i++)
            masao_vel[i] = getDouble();
        for(int i = 0; i < 3; i++)
            bo_pts[i] = getDouble();
        for(int i = 0; i < 3; i++)
            bo_vel[i] = getDouble();
        double l = 0, r = t;
        for(int lp = 0; lp < 1000; lp++) 
        {
            double t1 = l + (r-l)/3;
            double t2 = l + 2*(r-l)/3;
            double d1 = dist(masao_pts, masao_vel, bo_pts, bo_vel, t1);
            double d2 = dist(masao_pts, masao_vel, bo_pts, bo_vel, t2);
            if(d2 < d1)
                l = l + (r-l)/3;
            else if(d2 > d1)
                r = l + 2*(r-l)/3;
            else {
                l = l + (r-l)/3;
                r = l + 2*(r-l)/3;
            }
        }
        double d = dist(masao_pts, masao_vel, bo_pts, bo_vel, l);
        double ans = Math.sqrt(d);
        System.out.printf("%.6f\n", ans);
    }
    static BufferedReader br;
    static StringTokenizer strTok;
    static void initShinChanNohara() 
    {
        br = new BufferedReader(new InputStreamReader(System.in));
        strTok = null;
    }
    static void initShinChanNohara(String file) 
    {
        try 
        {
            br = new BufferedReader(new FileReader(file));
            strTok = null;
        }
        catch(FileNotFoundException e) 
        {
            writeln(e);
        }
    }
    static String getLine() 
    {
        try 
        {
            String st = br.readLine();
            return st;
        }
        catch(IOException e) 
        {
            return null;
        }
    }
    static String getToken() 
    {
        while(strTok == null || strTok.hasMoreTokens() == false) 
        {
            String st = getLine();
            if(st == null)
                return null;
            strTok = new StringTokenizer(st);
        }
        return strTok.nextToken();
    }
    static int getInt() 
    {
        return Integer.parseInt(getToken()); 
    }
    static double getDouble() 
    {
        return Double.parseDouble(getToken());
    }
    static long getLong() 
    {
        return Long.parseLong(getToken());
    }
    static void write(Object ... ob) 
    {
        for(int i = 0; i < ob.length; i++) 
        {
            if(i > 0)
                System.out.print(" ");
            System.out.print(ob[i]);
        }
    }
    static void writeln(Object ... ob) 
    {
        write(ob);
        System.out.println();
    }
    static void debug(Object ... ob) 
    {
        System.out.println(Arrays.deepToString(ob));
    }
}
