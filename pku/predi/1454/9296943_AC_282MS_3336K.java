import java.io.*;
import java.math.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
       BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            int n = Integer.parseInt(in.readLine());
            if( n == 0 ) break;
            BigInteger uno = new BigInteger("1");
            BigInteger dos = new BigInteger("2");
            BigInteger tres = new BigInteger("3");
            BigInteger cuatro = new BigInteger("4");
            BigInteger cinco = new BigInteger("5");
            BigInteger seis = new BigInteger("6");
            BigInteger siete = new BigInteger("7");
            BigInteger ocho = new BigInteger("8");
            BigInteger nueve = new BigInteger("9");
            BigInteger res = new BigInteger("1");
            BigInteger mul = new BigInteger("1");
            BigInteger diez = new BigInteger("10");
            for(int i = 1 ; i <= n ; i++){
                res = res.multiply(mul);
                mul = mul.add(uno);
            }
            BigInteger cero = BigInteger.ZERO;
            int a = 0 , b = 0 , c = 0 , d = 0 , e = 0 ,f = 0 , g = 0 , h = 0 ,  i = 0 , j = 0;
            while( res.compareTo(cero) != 0 ) {
                mul = res.mod(diez);
                if( mul.equals(cero) ) a++;
                if( mul.equals(uno) ) b++;
                if( mul.equals(dos) ) c++;
                if( mul.equals(tres) ) d++;
                if( mul.equals(cuatro) ) e++;
                if( mul.equals(cinco) ) f++;
                if( mul.equals(seis) ) g++;
                if( mul.equals(siete) ) h++;
                if( mul.equals(ocho) ) i++;
                if( mul.equals(nueve) ) j++;
                res = res.divide(diez);
            }
            System.out.println( n +"! --");
            if( a > 99) System.out.print("   (0)  "+a);
            else{
                    if(a > 9) System.out.print("   (0)   "+a);
                    else System.out.print("   (0)    "+a);
            }
            if( b > 99) System.out.print("   (0)  "+b);
            else{
                    if(b > 9) System.out.print("    (1)   "+b);
                    else System.out.print("    (1)    "+b);
            }
            if( c > 99) System.out.print("   (0)  "+c);
            else{
                    if(c > 9) System.out.print("    (2)   "+c);
                    else System.out.print("    (2)    "+c);
            }
            if( d > 99) System.out.print("   (0)  "+d);
            else{
                    if(d > 9) System.out.print("    (3)   "+d);
                    else System.out.print("    (3)    "+d);
            }
            if( e > 99) System.out.println("   (0)  "+e);
            else{
                    if(e > 9) System.out.println("    (4)   "+e);
                    else System.out.println("    (4)    "+e);
            }
            if( f > 99) System.out.print("   (0)  "+f);
            else{
                    if(f > 9) System.out.print("   (5)   "+f);
                    else System.out.print("   (5)    "+f);
            }
            if( g > 99) System.out.print("   (0)  "+g);
            else{
                    if(g > 9) System.out.print("    (6)   "+g);
                    else System.out.print("    (6)    "+g);
            }
            if( h > 99) System.out.print("   (0)  "+h);
            else{
                    if(h > 9) System.out.print("    (7)   "+h);
                    else System.out.print("    (7)    "+h);
            }
            if( i > 99) System.out.print("   (0)  "+i);
            else{
                    if(i > 9) System.out.print("    (8)   "+i);
                    else System.out.print("    (8)    "+i);
            }
            if( j > 99) System.out.println("   (0)  "+j);
            else{
                    if(j > 9) System.out.println("    (9)   "+j);
                    else System.out.println("    (9)    "+j);
            }
        }
    }
}