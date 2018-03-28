#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<map>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define ull unsigned long long int
#define all(v)  v.begin() , v.end()
#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull>

int q;
vi v;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd( b , a % b );
}

int mul(int a,int b,int c){
    int x = 0, y = a % c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
int modd(int a,int b,int c){
    int x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=mul(x,y,c);
        }
        y = mul(y,y,c); 
        b /= 2;
    }
    return x%c;
}

bool Miller(int p,int iteration){
    if(p<2)
        return false;
    
    if( p == 2 )
        return true;
        
    if(p!=2 && p%2==0){
        return false;
    }
    int s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        int a=rand()%(p-1)+1,temp=s;
        int mod=modd(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mul(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int rho(int n){
    if( n % 2 == 0 ) return 2;
    int x = 2 , y = 2 , d = 1;
    int c = rand() % n + 1;
    while( d == 1 ){
        x = (mul( x , x , n ) + c)%n;
        y = (mul( y , y , n ) + c)%n;
        y = (mul( y , y , n ) + c)%n;
        if( x - y >= 0 ) d = gcd( x - y , n );
        else d = gcd( y - x , n );
    }
    return d;
}

void factor(int n){
    if (n == 1) return;
    if( Miller(n , 2) ){
        v.push_back(n);
        return;
    }
    int divisor = rho(n);
    factor(divisor);
    factor(n/divisor);
}

void g(){
    sort( all(v) );
    
    printf("1");
    for(int i = 0 ; i < v.size() ; i++)
        printf(" x %d",(int)v[i]);
    
}

int main(){
    int n;
    while( scanf("%d",&n) == 1 ){
        if( n == 0 ) break;
        v.clear();
        q = n;
        if( n != 1 ){
            factor( n );
            g();
            printf("\n");
        }
        else printf("1\n");
    }
}

