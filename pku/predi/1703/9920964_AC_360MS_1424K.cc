#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<string>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf (1<<30)
#define me( arr , val ) memset( arr , val , sizeof(arr) );
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()
#define N 200005

int p[N] , n , m;

void makeset(int r){
    for(int i = 0 ; i <= r ; i++) p[i] = i ;
}

int FIND(int x){
    if( p[x] != x )
        p[x] = FIND( p[x] );
    return p[x];
}

void UNION(int x, int y){
    x = FIND(x);
    y = FIND(y);
    p[x] = y;
}

void doit(){
    scanf("%d %d\n", &n,&m);
    makeset( 2*n );
    char l;
    int x , y;
    for(int i = 0 ; i < m ; i++){
        scanf("%c %d %d\n",&l,&x,&y);
        x--,y--;
        if( l == 'A' ){
            int a = FIND(x) , b = FIND(y);
            if( a == b ) puts("In the same gang.");
            else if( FIND(x+n) == b ) puts("In different gangs.");
            else puts("Not sure yet.");
        }
        else{
            UNION( x , y + n ); UNION( x + n , y );
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}
