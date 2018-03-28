#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long a[10];
long long ini[10] = { 0 ,1 , 10 , 100 , 1000 , 10000 , 100000 , 1000000 , 1000000 , 10000000 };

int des(int n ,int lugar , int posi ){
    while( n > 0 ){
        int r = n % 10;
        n /= 10;
        if( posi == lugar ) return r;
        posi--;
    }
}

int f(int pos){
    int cantidad = 1;
    for(int i = 1 ; ; i++){
        if( a[i] >= pos ){ cantidad = i;  break; }
    }
    pos -= a[cantidad-1];
    //cout<<"pos "<<pos<<endl;
    int lugar = pos / cantidad;
    int fila = pos % cantidad;
    if( cantidad == 1 ) return lugar;
    if( pos % cantidad == 0 ){ lugar--; fila = cantidad;  }
    lugar = ini[cantidad] + lugar;
    //cout<<lugar<<" "<<fila<<endl;
    return des(lugar , fila , cantidad );
}

void doit(){
    int r;
    scanf("%d",&r);
    long long n = r;
    long long posi = 1;
    for(long long i = 1 ; ; i++){
        if( i*(i+1) >= 2*n ){ posi = i; break; }
    }
    long long p = ( posi*(posi-1) ) / 2;
    n -= p;
    cout<<f( n )<<endl;
}

int main(){
    a[0] = 0;
    a[1] = 9;
    for(int i = 2 ; i <= 9 ; i++){
        long long r = 8;
        for(int j = 1 ; j < i ; j++) r*=10;
        a[i] = (r+ a[i-1]/(i-1))* i;
    }
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t ; i++) doit();
}
