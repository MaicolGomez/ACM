import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in))); //como getline
        while( in.hasNext() ){
            BigDecimal base = in.nextBigDecimal();
            int n = in.nextInt();
            BigDecimal ans = base.pow(n);
            ans = ans.stripTrailingZeros();
            String s = ans.toPlainString();
            if( s.charAt(0) == '0' ) s = s.substring(1);
            System.out.println(s);
        }
    }
}
