import java.io.*;
import java.util.*;

public class L{

    static int[][][] chart;
    static int[][][] counter;

    public static void main(String[]args){
        Scan scan = new Scan();
        counter = new int[51][51][51];
        for(int i=0;i<=50;i++) for(int j=0;j<=50;j++) for(int k=0;k<=50;k++) counter[i][j][k] = -1;
        chart = new int[51][51][51];
        for(int i=0;i<=50;i++) for(int j=0;j<=50;j++) for(int k=0;k<=50;k++) chart[i][j][k] = -1;
        int testcases = scan.nextInt();
        while(testcases-- != 0){
            int n = scan.nextInt();
            int result = 0, counter = 0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    int temp = solve(n, i, j);
                    counter += temp;
                    result += chart[n][i][j];
                }
            }
 
            int divisor = gcd(result, counter);
            result /= divisor;
            counter /= divisor;
            System.out.println(result+"/"+counter);
        }
    }

    static int gcd(int a, int b){
        //System.out.println("gcd "+a+", "+b);
        if(a < b) return gcd(b, a);
        if(a%b == 0) return b;
        return gcd(b, a%b);
    }

    static int solve(int sum, int max, int use){
        if(counter[sum][max][use] != -1) return counter[sum][max][use];
        int count = 0, result = 0, digit = 1;
        if(max > 9) digit = 2;
        if(sum < use) ;
        else if(use == 0){
            if(sum == 0) count = 1;
            else count = 0;
        }else{
            int rest = sum - max;
            for(int i=0;i<=Math.min(rest, max);i++){
                count += solve(rest, i, use-1);
                result += chart[rest][i][use-1] + counter[rest][i][use-1]*digit;
            }
        }
        //System.out.printf("solve %d, %d, %d = %d, %d%n", sum, max, use, count, result);
        chart[sum][max][use] = result;
        return counter[sum][max][use] = count;
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
