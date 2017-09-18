import java.io.*;
import java.util.*;

public class E{
   
    static int outline, inlin;
    
    public static void main(String[] args){
        outline = inlin = 0;
        Scan scan = new Scan();
        int testcases = scan.nextInt();
        while(testcases-- != 0){
            int n = scan.nextInt();
            Point[] input = new Point[n];
            for(int i=0;i<n;i++) input[i] = new Point(scan.nextInt(), scan.nextInt());
            double[] r = new double[n];
            for(int i=0;i<n;i++) r[i] = input[i].distance(input[(i+1)%n]);
            inlin += (n+1);
            System.err.println("In:"+(inlin));
            if((n&1) > 0){
                double[] x = new double[n];
                Arrays.fill(x, -1);
                x[n-1] = r[n-1];
                for(int i=0;i<n-1;i++){
                    if((i&1)==0) x[n-1] -= r[i];
                    else x[n-1] += r[i];
                }
                x[n-1] /= 2;
                boolean noSolution = false;
                double result = 0.0;
                for(int i=n-2;i>=0;i--){
                    x[i] = r[i] - x[i+1];
                    if(x[i] < -0.01) noSolution = true;
                    result += x[i]*x[i];
                }
                if(x[n-1] < -0.01) noSolution = true;
                result += x[n-1]*x[n-1];
                result *= Math.PI;
                if(noSolution){
                    System.out.println("IMPOSSIBLE");
                    outline++;
                    System.err.println("Out:"+outline);
                    
                    continue;
                }
                
                System.out.printf("%.2f%n", result/2);
                for(int i=0;i<n;i++){
                    System.out.printf("%.2f%n", Math.abs(x[i]));
                }
                outline += (n+1);
                System.err.println("Out:"+outline);
            }else{
                double[] u = new double[n];
                u[0] = 0;
                for(int i=1;i<n;i++){
                    if((i&1) > 0) u[i] = u[i-1] - r[i-1];
                    else u[i] = u[i-1] + r[i-1];
                }
                
                double lowerBound = Double.MIN_VALUE, upperBound = Double.MAX_VALUE;
                double[] x = new double[n];
                x[0] = 0;
                for(int i=0;i<n;i+=2){
                    lowerBound = Math.max(lowerBound, -u[i]);
                    upperBound = Math.min(upperBound, -u[i|1]);
                    x[0] += u[i];
                    x[0] += u[i|1];
                }
                if(lowerBound - 0.01 > upperBound){
                    System.out.println("IMPOSSIBLE");
                    outline++;
                    System.err.println("Out:"+outline);
                    continue;
                }
                x[0] /= -(n);
                
                if(x[0] < lowerBound) x[0] = lowerBound;
                if(x[0] > upperBound) x[0] = upperBound;
                
                double result = x[0]*x[0];
                for(int i=1;i<n;i++){
                    x[i] = r[i-1] - x[i-1];
                    result += x[i]*x[i];
                }
                if(x[0] + x[n-1] != r[n-1]){
                    System.out.println("IMPOSSIBLE");
                    outline++;
                    System.err.println("Out:"+outline);
                    continue;
                }
                result *= Math.PI;
                System.out.printf("%.2f%n", result/2);
                for(int i=0;i<n;i++){
                    System.out.printf("%.2f%n", Math.abs(x[i]));
                }
                outline+=(n+1);
                System.err.println("Out:"+outline);
            }
        }
    }
    
    static class Point{
        
        int x, y;
        
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        
        double distance(Point rhs){
            return Math.sqrt((x-rhs.x)*(x-rhs.x) + (y-rhs.y)*(y-rhs.y));
        }
        
    }
    
}

class Scan{
    
    BufferedReader buffer;
    StringTokenizer tok;
    
    Scan(){
        buffer = new BufferedReader(new InputStreamReader(System.in));
    }
    
    boolean hasNext(){
        while(tok==null || !tok.hasMoreElements()){
            try{
                tok = new StringTokenizer(buffer.readLine());
            }catch(Exception e){
                return false;
            }
        }
        return true;
    }
    
    String next(){
        if(hasNext()) return tok.nextToken();
        return null;
    }
    
    int nextInt(){
        return Integer.parseInt(next());
    }
}
