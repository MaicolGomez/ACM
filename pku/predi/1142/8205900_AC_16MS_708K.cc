#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int sumadig(int r){
    int suma = 0;
    while( r > 0 ){ suma += r%10; r/=10; }
    return suma;
}

int sumades( int n ){
    int r = n;
    double p = sqrt( n );
    int suma = 0;
    for(int i = 2 ; i * i  <= r ; i++ ){
        if( r % i == 0 ){
            while( r % i == 0  ){
                suma += sumadig( i );
                r /= i;
            }
        }
    }
    if( int(p * p) <= n && r != 1 ){ suma += sumadig( r ); }
    return suma;
}
bool prime(int p){
    if( p == 2 || p == 3 ) return 1;
    if( p % 2 == 0 ) return 0;
    for(int i = 3 ; i * i <= p ; i+=2 ) if( p % i == 0 ) return 0;
    return 1;
}

int main(){
    int n;
    while( scanf("%d",&n) ){
        if(n == 0) break;
        for(int i = (n + 1) ; ; i++){
            if( prime(i) ) continue;
            if( sumades( i ) == sumadig( i ) ){ printf("%d\n",i); break; }
        }
    }
}
