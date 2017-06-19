import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.RoundingMode;
import java.util.StringTokenizer;
import java.text.DecimalFormat;


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author apirakhoonlor
 */
public class Spider {
    static class SPNode implements Comparable{
        public double dist;
        public long pop_level;
        public SPNode(double d, long p){
            dist = d;
            pop_level = p;
        }
        public int compareTo(Object target){
            SPNode tNode = (SPNode) target;
            if(dist > tNode.dist){
                return 1;
            }else if(dist < tNode.dist){
                return -1;
            }else{
                if(pop_level < tNode.pop_level){
                    return 1;
                }else if(pop_level > tNode.pop_level){
                    return -1;
                }
            }
            return 0;
        }
                
    }
    public int[][] popularity;
    public int[] distanceM;
    public int[] distanceN;
    public int N;
    public int M;
    public int Q;
    public DecimalFormat df = new DecimalFormat("#.00");
    
    
    public Spider(){
        df.setRoundingMode(RoundingMode.FLOOR);
    }
    
    public void solve(int p, int sx, int sy, int ex, int ey){
        int minX, minY, maxX, maxY;
        minX = Math.min(sx, ex);
        minY = Math.min(sy, ey);
        maxX = Math.max(sx, ex);
        maxY = Math.max(sy, ey);        
        int ROWS = Math.abs(maxY - minY);
        int COLS = Math.abs(maxX - minX);
        double[] TDistM = null;
        double[] TDistN = null;
        int i, j;
        // Set distances between Rows
        //System.out.println("N,ROWS=" + N + ","+ ROWS + "M,COLS=" + M + ","+ COLS);
        if(ROWS > 0){
            TDistN = new double[ROWS];
            if(sy == minY){
                for(i = 0; i < ROWS; i++){
                    TDistN[i] = (double) distanceN[sy+i];
                }
            }else{
                for(i = 0, j = ROWS-1; i < ROWS; i++,j--){
                    TDistN[j] = (double) distanceN[ey+i];
                }
            }
        }
        // Set distance between Cols
        if(COLS > 0){
            TDistM = new double[COLS];
            if(sx == minX){
                for(i = 0; i < COLS; i++){
                    //System.out.println("sy,i " + sy + "," + i);
                    TDistM[i] = (double) distanceM[sx+i];
                }
            }else{
                for(i = 0, j = COLS-1; i < COLS; i++,j--){
                    TDistM[j] = (double) distanceM[ex+i];
                }
            }
        }

//        System.out.println("Rows = " + ROWS + " Cols = " + COLS);        
        if(ROWS==0 && COLS == 0){
            System.out.println("0.00 " + p);
            return;
        }
        double totalDist = 0.0;
        if(ROWS == 0){
            for(i = 0; i < COLS; i++){
                totalDist += TDistM[i];
            }
            System.out.println(df.format(totalDist) + " " + p);
            return;
        }
        if(COLS == 0){
            for(i = 0; i < ROWS; i++){
                totalDist += TDistN[i];
            }
            System.out.println(df.format(totalDist) + " " + p);
            return;
        }
        // set preferences
        long[][] PP = new long[ROWS][COLS];
        int k,l, m;
        //if sx,sy < ex,ey
        if(sx < ex){
            if(sy < ey){
                for(i = 0; i < ROWS; i++){            
                    for(j = 0; j < COLS; j++){
                        PP[i][j] = popularity[sy+i][sx+j];
                    }
                }
            }else{
                //if sx < ex, sy > ey
                for(i = 0; i < ROWS; i++){
                    for(j = 0; j < COLS; j++){
                        PP[i][j] = popularity[sy-i-1][sx+j];
                    }
                }
            }
        }else{
        //if sx > ex, sy < ey
            if(sy < ey){
                for(i = 0; i < ROWS; i++){
                    for(j = 0; j < COLS; j++){
                        PP[i][j] = popularity[sy+i][sx-j-1];
                    }
                }
            }else{
        //if sx,sy > ex, ey
                for(i = 0; i < ROWS; i++){
                    for(j = 0; j < COLS; j++){
                        PP[i][j] = popularity[sy-i-1][sx-j-1];
                    }
                }
            } 
        }
        SPNode[][] OPT = new SPNode[ROWS+1][COLS+1];
        OPT[0][0] = new SPNode(0.0,(long)p);
        for(i = 1; i <= COLS; i++){
            OPT[0][i] = new SPNode(OPT[0][i-1].dist + TDistM[i-1], (long)p); 
        }
        for(i = 1; i <= ROWS; i++){
            OPT[i][0] = new SPNode(OPT[i-1][0].dist + TDistN[i-1], (long)p); 
        }
        double fromUp, fromLeft, fromD;
        SPNode fU, fL, fD;
        for(i = 1; i <= ROWS; i++){
            for(j = 1; j <= COLS; j++){
                fromUp = OPT[i-1][j].dist + TDistN[i-1];
                fromLeft = OPT[i][j-1].dist + TDistM[j-1];
                fromD = OPT[i-1][j-1].dist + euclDist(TDistN[i-1],TDistM[j-1]);
                fU = new SPNode(fromUp, OPT[i-1][j].pop_level);
                fL = new SPNode(fromLeft, OPT[i][j-1].pop_level);
                fD = new SPNode(fromD, OPT[i-1][j-1].pop_level + PP[i-1][j-1]);
                k = fU.compareTo(fL);
                if(fD.pop_level >= 0){
                    l = fU.compareTo(fD);     
                    m = fL.compareTo(fD);
                    if(k < 0){
                        if(l < 0){
                            OPT[i][j] = fU;
                        }else{
                            OPT[i][j] = fD;
                        }
                    }else{
                        if(m < 0){
                            OPT[i][j] = fL;
                        }else{
                            OPT[i][j] = fD;
                        }
                    }
                }else{
                    if(k < 0){
                        OPT[i][j] = fU;
                    }else{
                        OPT[i][j] = fL;
                    }
                }
            }
        }
        System.out.println(df.format(OPT[ROWS][COLS].dist) + " " + OPT[ROWS][COLS].pop_level);
        
    }
    
    public double euclDist(double x, double y){
        return Math.sqrt(Math.pow(x, 2.0)+Math.pow(y, 2.0));
    }
    
    public double euclDist(int ax, int ay, int bx, int by){
        double a_x = (double)ax;
        double a_y = (double)ay;
        double b_x = (double)bx;
        double b_y = (double)by;
        return Math.sqrt(Math.pow(a_x - b_x, 2.0)+Math.pow(a_y - b_y, 2.0));
    }
    
    public static void main(String[] args) throws IOException {        
         BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in)); 
         String line = stdin.readLine(); 
         int numTestCase = Integer.parseInt(line.trim());		 
         StringTokenizer numTokens;
         int i,j,k, p, sx, sy, ex, ey;
         Spider theMan = new Spider();
         for(i=0 ; i < numTestCase ; i++){                     
             line = stdin.readLine();
             numTokens = new StringTokenizer(line, " \t\r\n");
             theMan.N = Integer.parseInt(numTokens.nextToken());
             theMan.M = Integer.parseInt(numTokens.nextToken());
             theMan.Q = Integer.parseInt(numTokens.nextToken());
             theMan.distanceN = new int[theMan.N-1];
             theMan.distanceM = new int[theMan.M-1];
             theMan.popularity = new int[theMan.N-1][theMan.M-1];
             line = stdin.readLine();
             numTokens = new StringTokenizer(line, " \t\r\n");
             for(j = 0; j < theMan.N-1; j++){
                 theMan.distanceN[j] = Integer.parseInt(numTokens.nextToken());
             }
             line = stdin.readLine();
             numTokens = new StringTokenizer(line, " \t\r\n");
             for(j = 0; j < theMan.M-1; j++){
                 theMan.distanceM[j] = Integer.parseInt(numTokens.nextToken());
             }
             for(j = 0; j < theMan.N-1; j++){
                 line = stdin.readLine();
                 numTokens = new StringTokenizer(line, " \t\r\n");
                 for(k = 0; k < theMan.M-1; k++){                 
                    theMan.popularity[j][k] = Integer.parseInt(numTokens.nextToken());
                 }
             }
             for(j = 0; j < theMan.Q; j++){
                 line = stdin.readLine();
                 numTokens = new StringTokenizer(line, " \t\r\n");
                 p = Integer.parseInt(numTokens.nextToken());
                 sx = Integer.parseInt(numTokens.nextToken());
                 sy = Integer.parseInt(numTokens.nextToken());
                 ex = Integer.parseInt(numTokens.nextToken());
                 ey = Integer.parseInt(numTokens.nextToken());
                 theMan.solve(p,sx,sy, ex, ey);
             }             
         }
         
    }
    
}
