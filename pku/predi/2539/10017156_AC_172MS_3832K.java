import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while( sc.hasNext() ){
            BigInteger t = sc.nextBigInteger();
            int a = sc.nextInt() , b = sc.nextInt();
            System.out.print("(" + t + "^" +a+ "-1)/("+t+"^"+b+"-1) ");
            if( t.compareTo( new BigInteger("1") ) == 0  || a%b != 0 ){
                System.out.println("is not an integer with less than 100 digits.");
                continue;
            }
            BigInteger MAXN = new BigInteger("10").pow(100);
            BigInteger pot = new BigInteger("1");
            BigInteger X = new BigInteger("1");
            for(int i = 0 ; i < b ; i++){
                pot = pot.multiply(t);
                if( pot.compareTo(MAXN) >= 0 ) break;
            }
            BigInteger S = new BigInteger("0");
            for(int i = 0 ; i < a/b ; i++){
                S = S.add( X );
                if( S.compareTo(MAXN) >= 0 ) break;
                X = X.multiply(pot);
            }
            if( S.compareTo(MAXN) >= 0 ) System.out.println("is not an integer with less than 100 digits.");
            else System.out.println(S);
        }
    }
}
