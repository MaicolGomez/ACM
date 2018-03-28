
import java.math.*;
import java.util.*;

public class Main {
    
    public static BigInteger [][] t = new BigInteger [205][205];
    public static int n;
    public static BigInteger one = new BigInteger( 1 + "" );
    
    public static BigInteger f(int ini ,int fin){
        if( ini == fin ) return new BigInteger( 0 + "" );
        if( ini > fin || ini + 1 == fin ) return one;
        if( t[ini][fin].compareTo(one.negate()) != 0 ) return t[ini][fin];
        BigInteger ret = new BigInteger( 0 + "" );
        
        for(int i = ini + 1 ; i <= fin ; i++)
            ret = ret.add( f( ini+1  , i - 1  ).multiply( f( i+1 , fin ) ) );
        
        t[ini][fin] = ret;
        return ret;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner( System.in );
        for(int i = 0 ; i <= 200 ; i++) for(int j = 0 ; j<= 200 ; j++) t[i][j] = one.negate();
        while( in.hasNext() ){
            n = in.nextInt();
            if( n == -1 ) break;
            System.out.println( f( 0 , 2 * n - 1 ) );
        }
    }
}
