import java.io.*;
import java.util.*;

public class FastACM {
    static long bestCost(int w[]) {
        long total=0, sum=0;
        for (int i=0;i<w.length;++i) { total += w[i]; }
        for (int m=0;m<w.length;++m) {
            if (2*sum <= total && 2*(total-sum-w[m]) <= total) {
                // location is m on this axis
                // System.err.println("m:"+m);
                sum=0;
                for (int i=0;i<w.length;++i) { sum += Math.abs(m-i)*(long) w[i]; }
                break;
            }
            sum += w[m];            
        }
        return sum;       
    }
    static long solve(int x[], int y[], int z[]) {
        int wx[] = new int[x.length];
        int wy[] = new int[y.length];
        int wz[] = new int[z.length];
        
        for (int i=0;i<x.length;++i) 
            for (int j=0;j<y.length;++j)
                for (int k=0;k<z.length;++k) {
                    int xyz = x[i] ^ y[j] ^ z[k]; 
                    wx[i] += xyz; wy[j] += xyz; wz[k] += xyz;
                }
        
        return bestCost(wx) + bestCost(wy) + bestCost(wz);
    }
    public static void main(String[] args)  {        
        Scanner in = new Scanner(System.in);
        int numCases=in.nextInt();
        
        for (int k=0;k<numCases;++k) {
            int info[][] = new int[3][];
            for (int d=0;d<3;++d) {
                int n=in.nextInt();
                info[d] = new int[n];
                for (int i=0;i<n;++i) { info[d][i]=in.nextInt(); }
            }
            System.out.println(solve(info[0], info[1], info[2]));
        }
        in.close();
    }
}

